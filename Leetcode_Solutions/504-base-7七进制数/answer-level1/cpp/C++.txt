```
击败100%
class Solution {
public:
	string convertToBase7(int num) {
		string res;
		if (num == 0) return "0";
		if (num>0)
		{
			while (num>0)
			{
				res = to_string(num % 7) + res;
				num = num/7;
			}
		}
		if (num<0)
		{
			
			int temp = abs(num);
			while (temp>0)
			{
				res = to_string(temp % 7) + res;
				temp = temp / 7;
			}
			res = '-' + res;
		}
		return res;

	}
};
```
