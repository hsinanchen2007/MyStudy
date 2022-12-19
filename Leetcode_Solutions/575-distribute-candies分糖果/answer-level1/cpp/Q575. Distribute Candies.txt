简单题，题目的意思就是要给妹妹分的糖果的种类尽可能多，也就是糖果的种类和糖果数量的一半取较小值。
那么怎么计算糖果有多少种呢？最直观的做法就是排序去重，最简明的方法就是使用unordered_set。
```
class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		std::unordered_set<int> setKindsOfCandies;
		for (vector<int>::size_type i = 0; i< candies.size(); ++i) {
			setKindsOfCandies.insert(candies[i]);
		}

		return std::min(candies.size() / 2, setKindsOfCandies.size());
	}
};
```
我果真不适合写题解，写文章啊！