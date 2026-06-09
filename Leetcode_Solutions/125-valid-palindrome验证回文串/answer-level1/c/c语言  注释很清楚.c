bool isPalindrome(char * s){
    int i = 0;
	int j = strlen(s) - 1;
    首尾同时开始检测是否为数字或字符，当首尾相交时判断结束
	while (i <= j){
        //判断是否为数字或字符，如果不是则跳过
		while ((s[i] < '0' || (s[i] > '9' && s[i] < 'A') \
			|| (s[i] > 'Z' && s[i] < 'a') || s[i] > 'z') && i < j)
		{
			i++;
		}
        //判断是否为数字或字符，如果不是则跳过
		while ((s[j] < '0' || (s[j] > '9' && s[j] < 'A') \
			|| (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z') && i < j)
		{
			j--;
		}
        //当两个都是字母时，进行判断
		if (s[i] > '9' && s[j] > '9' && i < j)
		{
			if (s[i] == s[j] || s[i] + 32 == s[j] || s[i] - 32 == s[j])
			{
				i++;
				j--;
				continue;
			}
			break;
		}
        //当两个都是数字时进行判断
		else if (s[i] < 'A' && s[j] < 'A' && i < j)
		{
			if (s[i] == s[j])
			{
				i++;
				j--;
				continue;
			}
			break;
		}
        //两个不同为字母或数字，那么必不相等，直接跳出
		else
			break;
	}
    //如果i和j相聚了，说明回文
	if (i >= j)
		return 1;
	else
		return 0;

}