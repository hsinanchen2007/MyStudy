c++ 一次遍历
```
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> res(digits);
		if (digits[0] == 0)
		{
			res[0] = 1;
			return res;
		}

		int index = digits.size() - 1;
		int mod = 0;
        
		while (index >= 0 && mod == 0)
		{
			res[index] += 1;
			mod = res[index--] % 10;
		}
		
		if (mod == 0)
		{
			res.insert(res.begin(), 1);
		}
		return res;
	}
};
```

