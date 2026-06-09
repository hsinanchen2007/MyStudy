主要是用两个计数值来标记L和R的个数， 最开始这两个计数值都为0， 然后开始遍历字符串，当检测到第一个字符时，把对应的计数值+1， 然后每检测到另一个字符，就把相应的计数值-1， 同样的字符，检测到之后计数值就+1，当计数值归0时，可以判断找到一个字串。以此类推，直到把字符串遍历完。
```
int balancedStringSplit(string s) {
	int count = 0, count_L = 0, count_R = 0;
    for(int i = 0; i < s.length(); ++i)
    {
    	if(count_L == 0 && count_R == 0)
    	{
	    	if(s[i] == 'R')
	    		count_R++;
			else if(s[i] == 'L')
	    		count_L++;
		}
		else if(count_L > 0)
		{
			if(s[i] == 'R')
	    	{
	    		count_L--;
	    		if(count_L == 0)
	    			count++;
			}
			else if(s[i] == 'L')
	    		count_L++;
		}
		else if(count_R > 0)
		{
			if(s[i] == 'R')
	    		count_R++;
			else if(s[i] == 'L')
	    	{
	    		count_R--;
	    		if(count_R == 0)
	    			count++;
			}
		}
	}
	return count;
}
```
