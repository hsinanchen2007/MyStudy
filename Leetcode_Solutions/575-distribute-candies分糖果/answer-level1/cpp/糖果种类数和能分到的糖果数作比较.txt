糖果种类数大于能分到的糖果数，则最终只能分到能分到的糖果数的种类数，否则有多少种类糖果就能分到多少种。
```C++ []
class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		unordered_set<int> s;
		for (int c : candies)
			s.insert(c);
		int n = s.size();	//糖果种类数
		int m = candies.size() / 2;	//能分到的糖果数
		return n > m ? m : n;
	}
};
```
