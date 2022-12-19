**执行用时 :8 ms, 在所有 C 提交中击败了62.20%的用户
内存消耗 :6.6 MB, 在所有 C 提交中击败了61.74%的用户**

`
int titleToNumber(char * s){

    int i = 0;
	int x = 0;
	int num = 0;
	while(s[i] != '\0')
	{
		i++;
	}
	for(;i > 0;i--)
	{
		num += ((int)(s[i-1] - 64)) * pow(26,x);
		x++;
	}
	return num;
}`