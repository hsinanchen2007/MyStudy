class Solution {
public:
	string addStrings(string num1, string num2) {
		int c = 0;
		if (num1.length() >= num2.length())
		{
			while (num1.length() > num2.length())
			{
				num2 = '0' + num2;
			}
			for (int i = num2.length() - 1; i >= 0; i--)
			{
				c += (num2[i] - '0') + (num1[i] - '0');
				if (i == 0)
				{
					if (c >= 10)
					{
						num1[0] = c % 10 + '0';
						num1 = '1' + num1;
						break;
					}
				}
				if (c >= 10)
				{
					num1[i] = '0'+c%10;
				}
				else
				{
					num1[i] = '0'+c;
				}
				c /= 10;
			}
			return num1;
		}
		else
		{
			while (num1.length() < num2.length())
			{
				num1 = '0' + num1;
			}
			for (int i = num1.length() - 1; i >= 0; i--)
			{
				c += (num2[i] - '0') + (num1[i] - '0');
				if (i == 0)
				{
					if (c >= 10)
					{
						num2[0] = c % 10 + '0';
						num2 = '1' + num2;
						break;
					}
				}
				if (c >= 10)
				{
					num2[i] = '0'+c % 10;
				}
				else
				{
					num2[i] = '0'+c;
				}
				c /= 10;
			}
			return num2;
		}
	}
};
