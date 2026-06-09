int compress(char* chars, int charsSize){
	char temp = '0';//设置初始变量
	int j = 0;
	int m = 1;
	int l = 0;
	for (int i = 0; i<charsSize; i++)
	{
		if (temp != chars[i])//第一个位置和初始变量比较
		{
			temp = chars[i];
			if (i != 0)
			{
				chars[j++] = '0' + l;
			}
			chars[j++] = temp;
			l = 0;
			l++;
		}
		else
		{
			if (l == 9)
			{
				chars[j++] = '0' + m;
				m++;
				l = 0;
			}
			else
			{
				l++;
			}
		}
	}
	chars[j++] = '0' + l;
	chars[j] = '\0';
	printf("%d\n", j);
	return 0;
}