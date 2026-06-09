class Solution {
public:
	string intToRoman(int num) {
		vector<char> table={'I','V','X','L','C','D','M'};
		/*string table;
		table = "IVXLCDM";*/
		string res;
		if (1 <= num&&num <= 3999)
		{
			int i = 0;
			while (num>0)
			{
				int temp = num % 10;
				if (temp<4)
				{
					for (int j = 0; j<temp; ++j)
						res = table[2 * i] + res;
				}
				else if (temp == 4)
				{
					res = table[2 * i + 1] + res;
					res = table[2 * i] + res;
				}
				else if (temp == 5)
				{
					res = table[2 * i + 1] + res;
				}
				else if (temp<9)
				{
					for (int j = 0; j<temp - 5; ++j)
						res = table[2 * i] + res;
					res = table[2 * i + 1] + res;
				}
				else
				{
					res = table[2 * i] + (table[2 * i + 2] + res);
				}
				++i;
				num = num / 10;
			}
			return res;
		}
		else
			return res;
	}
};