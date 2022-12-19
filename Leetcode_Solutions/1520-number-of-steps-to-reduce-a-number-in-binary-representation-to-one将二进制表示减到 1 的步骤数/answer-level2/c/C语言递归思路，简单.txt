int numSteps(char * s){
    if (strlen(s) == 1 && s[0] == '1')
		return 0;
	else
	{
		int sum = 0;
        sum++;
		if (s[strlen(s) - 1] == '0')
		{
			s[strlen(s) - 1] = '\0';
			sum += numSteps(s);
		}
		else
		{
			int flag = 1;
			int num = 0;
			int i;
			for (i = strlen(s) - 1; i >= 0; i--)
			{
					if (s[i] == '1')
						s[i] = '0';
					else
					{
						s[i] = '1';
						flag = 0;
                        break;
					}
			}
			if (flag == 1)
			{
                char *res = (char *)malloc(sizeof(char)*(strlen(s) + 2));	 //注意是要+2，还有一个'\0'
                sprintf(res,"1%s",s);
                sum=sum+numSteps(res);
            }
            else
            {
                sum=sum+numSteps(s);
            }
        }
     return sum;
	}
	return 0;
}