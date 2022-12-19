int lengthOfLongestSubstring(char * s){
	int n = 0,length = 0;
	int st=0,e=0;
	int i = 0,j;
	while(s[i]!='\0')//终止条件
	{
		for(j = st;j < e;j++)//循环找是否有相等元素
		{
			if(s[i] == s[j])
				break;
		}
		if(j == e)//判断条件：未找到相等元素
			e++;
		else
		{
			n = (e - st)>n?(e - st):n; 
			st = j+1;//将重复元素移除
			e ++; //收入判断元素;

		}
		i++;
	}
    n = (e - st)>n?(e - st):n;
	return n;
}
