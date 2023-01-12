#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "args too less!\n");
		return -1;
	}
	cout << "start getting FIB" << endl;
	int num_ipv4 = 0; // Number of ipv4 entries in this FIB
	int num_ipv6 = 0; // Number of ipv6 entries in this FIB
	int num;
	int arry_ipv4[33];	// Number of prefixes per length, 0~32
	int arry_ipv6[129]; // Number of prefixes per length, 0~128
	FILE *read;
	FILE *write_ipv4;
	FILE *write_ipv6;
	read = fopen(argv[1], "r"); // read the bgpdump data
	if (read < 0)
	{

		fprintf(stderr, "unable to open trace %s\n", argv[1]);
		perror("trace file open");
		return -1;
	}
	write_ipv4 = fopen("../data/ipv4_FIB.txt", "w+"); // write FIB into this file( creat this file first)
	write_ipv6 = fopen("../data/ipv6_FIB.txt", "w+"); // write FIB into this file( creat this file first)
	char data[10000];
	string str1, str2;
	memset(arry_ipv4, 0, sizeof(int) * 129);
	memset(arry_ipv6, 0, sizeof(int) * 129);
	while (!feof(read))
	{
		str2.clear();
		fgets(data, 10000, read);
		for (int begin = 0, flag = 0; data[begin] != '\0'; begin++)
		{
			if (data[begin] == '|')
			{
				flag++;
			}
			if (flag == 5)
			{
				begin++;
				int index_len;
				int is_ipv4 = 1;
				for (int len = 0; data[begin + len] != '|'; len++)
				{
					if (data[begin + len] == '/')
						index_len = len + 1;
					if (data[begin + len] == ':')
						is_ipv4 = 0;
					str2 = str2 + data[begin + len];
				}
				if (str1 != str2) // start writting
				{
					num++;
					// str2 is the prefix
					//  cout<<str2<<endl;
					//  cout<<num<<endl;
					int a = 0, b = 0, c = 0;
					if (str2.size() - index_len == 2)
					{
						b = str2[index_len] - '0';
						c = str2[index_len + 1] - '0';
					}
					else if (str2.size() - index_len == 3)
					{
						a = str2[index_len] - '0';
						b = str2[index_len + 1] - '0';
						c = str2[index_len + 2] - '0';
					}
					else
					{
						c = str2[index_len] - '0';
					}
					int index = a * 100 + b * 10 + c;
					// if(index==1)
					//{

					// cout<<data;
					// system ("pause");
					//}
					// char port[5];
					// itoa(index, port, 10);//��10����ת�����ַ�����
					char prefix[str2.size()];
					strcpy(prefix, str2.c_str());
					char port[5];
					sprintf(port, "%d", index);
					if (is_ipv4 == 1)
					{
						num_ipv4++;
						arry_ipv4[index]++;
						fputs(prefix, write_ipv4);
						fputc('\t', write_ipv4);
						fputs(port, write_ipv4);
						fputc('\n', write_ipv4); // write the ipv4 prefix into file
					}
					else
					{
						arry_ipv6[index]++;
						num_ipv6++;
						fputs(prefix, write_ipv6);
						fputc('\t', write_ipv6);
						fputs(port, write_ipv6);
						fputc('\n', write_ipv6); // write the ipv6 prefix into file
					}
				}
				str1.clear();
				str1 = str2;
				break;
			}
		}
	}
	fclose(read);
	fclose(write_ipv4);
	fclose(write_ipv6);
	cout << "\nSuccess!" << endl;
	cout << "The numble of ipv4 prefix is " << num_ipv4 << endl;
	cout << "Length of Prefix	 Quantity       Percent\n";
	for (int i = 1; i <= 32; i++)
	{
		if (arry_ipv4[i] == 0)
			continue;
		double x = double(arry_ipv4[i]) / num_ipv4;
		x *= 100;
		printf("   %3d		    %10d  	 %5.2f\n", i, arry_ipv4[i], x);
	}
	cout << "The numble of ipv6 prefix is " << num_ipv6 << endl;
	cout << "Length of Prefix	 Quantity       Percent\n";
	for (int i = 1; i <= 128; i++)
	{
		if (arry_ipv6[i] == 0)
			continue;
		double x = double(arry_ipv6[i]) / num_ipv6;
		x *= 100;
		printf("   %3d		    %10d  	 %5.2f\n", i, arry_ipv6[i], x);
	}
	return 0;
}
