### 解题思路
首先确定第一个字母对应的数字大小，之后检查后一个字母对应的大小是否大于前一个，如果大，则为特殊情况，
此时则减去二倍的上一个字母对应的大小，再加上本字母对应的大小。

### 代码

```c
int romanToInt(char * s){
	char map[7] = "IVXLCDM";
	int key[7] = {1,5,10,50,100,500,1000};
	int len=strlen(s);
	int x=0,num=0;
    int a=0;
	int i,j;

	while(x!=len)
	{
		for(i=0;i<7;i++)
		{
			if(s[x]==map[i])
			{
				num=num+key[i];
				x++;
                break;
			}
		}
        for(j=i+1;j<7;j++)
		{
			if(s[x]==map[j])
			{
				num=num+key[j]-2*key[i];
                x++;
                break;
			}
		}
	}
	return num;
}
```