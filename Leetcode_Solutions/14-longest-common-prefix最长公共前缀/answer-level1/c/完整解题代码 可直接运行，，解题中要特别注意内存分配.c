### 解题思路
此处撰写解题思路

### 代码

```c
#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
char * longestCommonPrefix(char ** strs, int strsSize) {
	if(strs==NULL) {
		char* temp=(char*)malloc(1);
		temp[0] = '\0';
		return temp;
	}
	if(strsSize==0){
		char* temp=(char*)malloc(1);
		temp[0] = '\0';
		return temp;
	}

	int i,count=0;
	int flag = true;
	char*str=(char*)malloc(sizeof(char)*1000);
	while(flag){
		char c=strs[0][count];
		for(i=0;i<strsSize;i++){
			if(c!=strs[i][count] || strs[i][count]=='\0'){
				flag=false;
				break;
			}
		}
		str[count]=c;
		count++;
		
	}
	str[count-1] = '\0';
	return str;
}

int main(void) {

	char *str[1000];
	char **strs=str;

	int strsSize;
	scanf("%d",&strsSize);

	int i;
	for(i=0; i<strsSize; i++) {
		//给每个指针开辟一定的空间来存放字符串 
		str[i]=(char*)malloc(sizeof(char)*100);
		scanf("%s",str[i]);
		printf("%s ",strs[i]);
	}

	char*res=longestCommonPrefix(strs,strsSize);
	printf("\n res = %s\n",res);

	return 0;
}