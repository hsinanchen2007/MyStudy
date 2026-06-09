### 解题思路
此处撰写解题思路

### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize)
{
if (strsSize==0)
return "";
char*ami=strs[0];
int i,j;
for(i=1;i<strsSize;i++)
	{
	for(j=0;strs[0][j]!='\0'&&strs[i][j]!='\0';j++)
		{
		if(strs[0][j]!=strs[i][j])
		break;
		}
	ami[j]='\0';
	if(ami[0]=='\0')
		return "";
		}
return ami;
}
```