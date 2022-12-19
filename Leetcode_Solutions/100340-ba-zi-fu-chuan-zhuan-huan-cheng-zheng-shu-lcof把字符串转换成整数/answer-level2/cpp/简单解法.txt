    int myAtoi(string str) 
    {
		if (str.empty()) throw std::exception("invalid input");
		long long result = 0;
		int i = 0;
		int flag = 0; //flag = 0 means result is a positive num, or it's a negetive num.
		while (str[i] == ' ')
		{
			i++;
		}
		if (isalpha(str[i]))
		{
			return 0;
		}
		else if (str[i] == '+')
		{
			i++;
		}
		else if (str[i] == '-')
		{
			flag = 1;
			i++;
		}
		while (isdigit(str[i]) && i < str.size())
		{
			result = (str[i] - '0') + 10 * result;
			i++;
			if (flag && -result < INT32_MIN)
			{
				return INT32_MIN;
			}
			if (!flag && result > INT32_MAX)
			{
				return INT32_MAX;
			}

		}
		return flag ? -result : -result;
    }
