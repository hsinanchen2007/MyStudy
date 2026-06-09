### 解题思路
此处撰写解题思路

### 代码

```c
int isValid(char * s)
{
int length=strlen(s);
if(length==0)
return 1;
int *mark=(int*)malloc(sizeof(int)*length);
int i;
int count=-1;
for(i=0;i<length;i++)
	{
	if(*(s+i)==')')
		{
		if(count>-1&&*(mark+count)=='(')
			count--;
		else
			return 0;
		}
	else if(*(s+i)==']')
		{
		if(count>-1&&*(mark+count)=='[')
			count--;
		else
			return 0;
		}
	else if(*(s+i)=='}')
		{
		if(count>-1&&*(mark+count)=='{')
			count--;
		else
			return 0;

		}
	else
		*(mark+(++count))=s[i];
	}
if(count>-1)
return 0;
return 1;
}
```