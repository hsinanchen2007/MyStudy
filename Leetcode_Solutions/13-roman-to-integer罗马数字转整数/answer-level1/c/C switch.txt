```
int romanToInt(char * s){
	
	if( s == NULL)
	{
		return -1;
	}
	
	int result = 0;
	
	for(int i = 0; s[i] != '\0';)
	{
		switch(s[i])
		{
			case 'I':
				switch(s[i + 1])
				{
					case 'V':
						result += 4;
						i += 2;
						break;
					case 'X':
						result += 9;
						i += 2;
						break;
				    default:
						result += 1;
						i += 1;
				}
				break;
			case 'X':
				switch(s[i + 1])
				{
					case 'L':
						result += 40;
						i += 2;
						break;
					case 'C':
						result += 90;
						i += 2;
						break;
				    default:
						result += 10;
						i += 1;
				}
				break;
			case 'C':
				switch(s[i + 1])
				{
					case 'D':
						result += 400;
						i += 2;
						break;
					case 'M':
						result += 900;
						i += 2;
						break;
				    default:
						result += 100;
						i += 1;
				}
				break;
			case 'V':
				result += 5;
				i += 1;
				break;
			case 'L':
				result += 50;
				i += 1;
				break;
			case 'D':
				result += 500;
				i += 1;
				break;
			case 'M':
				result += 1000;
				i += 1;
				break;
			default:
				return -1;
		}
	}
	return result;
}
```
对于特殊 I、X、C 多加一个switch判断
