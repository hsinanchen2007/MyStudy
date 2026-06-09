### 解题思路
此处撰写解题思路

### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0)
    return "";
    if(*((*strs))=='\0')
    return "";
    if(strsSize==1)
    return *(strs);
//以上是特殊情况
	int arr[126]={0};
	int num=0;
	int len=strlen(*(strs));
	int is_true=1;
	while(is_true&&num<len)
	{
		arr[(int)*((*strs)+num)]=1;
		for(int i=0;i<strsSize;i++)
		{
			if(arr[(int)*(*(strs+i)+num)]==0)
			{
				is_true=0;
			}
		}
		arr[(int)*((*strs)+num)]=0;
        num++;
	}
	if(num==len&&is_true==1)
	{
		num++;
	}
	char*s=(char*)malloc(num);
	*(s+num-1)='\0';
	for(int i=0;i<num-1;i++)
	{
		*(s+i)=*((*strs)+i);
	}
	return s;
}
```