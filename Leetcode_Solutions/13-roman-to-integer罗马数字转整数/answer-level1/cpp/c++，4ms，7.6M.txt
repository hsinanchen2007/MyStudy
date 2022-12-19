class Solution {
public:
	int romanToInt(string s) {
		
		int i = 0;
		int value = 0;
		int result=0;
		while (1)
		{
			switch (s[i])
			{
			case 'I':
				if (s[i + 1] == 'V')
				{
					value = 4;
					i++;
				}
				else if (s[i + 1] == 'X')
				{
					value = 9;
					i++;
				}
				else
					value = 1;
				break;
			case 'V':
				value = 5;
				break;
			case 'X':
				if (s[i + 1] == 'L')
				{
					value = 40;
					i++;
				}
				else if (s[i + 1] == 'C')
				{
					value = 90;
					i++;
				}
				else
					value = 10;
				break;
			case 'L':
				value = 50;
				break;
			case 'C':
				if (s[i + 1] == 'D')
				{
					value = 400;
					i++;
				}
				else if (s[i + 1] == 'M')
				{
					value = 900;
					i++;
				}
				else
					value = 100;
				break;
			case 'D':
				value = 500;
				break;
			case 'M':
				value = 1000;
				break;
			default:
				break;
			}
			result += value;
			i++;
			if (result > 3999|| i == s.size())
				break;		
		}
		if (result <= 3999)
		
			return result;
		else
			return 0;
	
		
	}
};