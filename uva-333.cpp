#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

char buf[100];
int save[10];

int main()
{
	while(cin.getline(buf,100))
	{
		int start=0,end=strlen(buf)-1;
		while(buf[start]==' ')
			start++;//不读开头的空格
		while(buf[end]==' ')
			buf[end--]=0;//不读结尾的空格
		int flag=0,count=0;
		for(int i=start;buf[i];++i) 
		{
			if((buf[i]>='0'&&buf[i]<='9')||(buf[i]=='X'&&count==9))
				save[count ++] = buf[i]=='X'?10:buf[i]-'0';
			else if (buf[i] != '-') {
				flag = 1;
				break;
			}
			if (count > 10) {
				flag = 1;
				break;
			}
		}
		
		if (count != 10) flag = 1;
		for (int i = 1 ; i < 10 ; ++ i)
			save[i] += save[i-1];
		for (int i = 1 ; i < 10 ; ++ i)
			save[i] += save[i-1];
		if (save[9]%11) flag = 1;
		
		printf("%s is ",&buf[start]);
		if (flag)
			printf("incorrect.\n");
		else printf("correct.\n");
	}
    return 0;
}
