#include<bits/stdc++.h>
using namespace std;
int main()
{


	FILE* read;
	read=fopen("20220110_ipv4.txt","r");//read table_dump2 from this file
    char data[1024];
    int n=0;
   while(!feof(read))
  {
   n++;
   fgets(data, 1024, read);
   for(int i=0;;i++)
   {
   	if(data[i]=='\0')
   	{
   	     if(i<8)
		{
	
		cout<<data<<endl;
		cout<<"line:"<<n;
		//system("pause");
		}
   		break;	
		
	}
   }

	}  

   return 0;
}
