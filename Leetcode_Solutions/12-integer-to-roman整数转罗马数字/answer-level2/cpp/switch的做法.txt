```
class Solution {
public:
	string intToRoman(int num) {
		int Ten = 10;
		vector<int> a = {0,0,0,0};
		for (int i = 0; i < 4; i++)
		{
			a[i] = num % Ten;
			num /= 10;
		}

		vector<string> out(4);
		string l, m, n;
		for (int i = 0; i < 4; i++)
		{
			switch (i)
			{
			case 0:
				l = 'I'; m = 'V'; n = 'X';
				break;
			case 1:
				l = 'X'; m = 'L'; n = 'C';
				break;
			case 2:
				l = 'C'; m = 'D'; n = 'M';
				break;
			case 3:
				l = 'M'; m = {}; n = {};
				break;
			default:
				break;
			}

			switch (a[i])
			{
			case 0:
				break;
			case 1:
				out[i] = {l};
				break;
			case 2:
				out[i] = {l+l};
				break;
			case 3:
				out[i] = {l+l+l};
				break;
			case 4:
				out[i] = {l+m};
				break;
			case 5:
				out[i] = {m};
				break;
			case 6:
				out[i] = {m+l};
				break;
			case 7:
				out[i] = {m+l+l};
				break;
			case 8:
				out[i] = {m+l+l+l};
				break;
			case 9:
				out[i] = {l+n};
				break;
			default:
				break;
			}
		}

		string str = out[3] + out[2] + out[1] + out[0];
		return str;
	}
};
```
