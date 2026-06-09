执行结果：通过显示详情
执行用时 :8 ms, 在所有 c 提交中击败了100.00%的用户
内存消耗 :6.8 MB, 在所有 c 提交中击败了100.00%的用户
```
int minimumSwap(char * s1, char * s2)
{
	/*  x  y
		y  x   */
	int len=strlen(s1),cntxy=0,cntyx=0;
	for (int i=0;i<len;i++)
	{
		if (s1[i]=='x' && s2[i]=='y'){cntxy++;}
		if (s1[i]=='y' && s2[i]=='x'){cntyx++;}
	}
	if ((cntxy+cntyx)%2){return -1;}
	return (cntxy+1)/2+(cntyx+1)/2;
}
```
