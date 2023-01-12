#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "args too less!\n");
		return -1;
	}

	FILE *read;
	read = fopen(argv[1], "r");
	if (read < 0)
	{

		fprintf(stderr, "unable to open FIB %s\n", argv[1]);
		perror("FIB  open");
		return -1;
	}
	char data[1024];
	int n = 0;
	while (!feof(read))
	{
		n++;
		fgets(data, 1024, read);
		for (int i = 0;; i++)
		{
			if (data[i] == '\0')
			{
				if (i < 8)
				{

					cout << data << endl;
					cout << "line:" << n;
					// system("pause");
				}
				break;
			}
		}
	}

	return 0;
}
