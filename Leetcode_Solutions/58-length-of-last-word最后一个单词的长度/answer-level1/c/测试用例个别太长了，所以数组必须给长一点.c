int lengthOfLastWord(char * s)
{
	int len = strlen(s);
	if (len == 0)
		return 0;
	if (len == 1 && *s != ' ')
		return 1;
	int i = 0;
	int cur = 0;
	int k = 0;
	int nums[100] = {0};
	while (s[i])
	{
		if (s[i] != ' ')
		{
			++cur;
		}
		else
		{
			nums[k] = cur;
			++k;
			cur = 0;
		}
		++i;
	}
	nums[k] = cur;
	for (int j = 99; j >= 0; --j)
	{
		if (nums[j] != 0)
			return nums[j];
	}
	return 0;

}