直接模拟解题过程即可。
1. 将`products`按照字典序排序。
2. 了解到下面这一点：当计算前`i`个字符为前缀的产品时，如果第`k`个产品`products[k]`的前缀不满足，那么`k`前面的也一定都不满足，一定是从`k`位置后面找；同时，下一步计算前`i+1`个字符为前缀的产品时，它的起始位置一定是后面位置，前面的产品名一定不是。
```
class Solution {
public:
	vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
		vector<vector<string>> ansVec;
		std::sort(products.begin(), products.end());
		string prefixStr = "";
		for (size_t i = 0, k = 0; i < searchWord.size(); ++i) {
			prefixStr += searchWord.at(i);
			// 查找并记录第一个
			while (k < products.size() && products[k].find(prefixStr) != 0) {
				++k;
			}

			vector<string> vecAns;
			for (size_t j = k; j < products.size() && vecAns.size() < 3 && products[j].find(prefixStr) == 0; ++j) {
				vecAns.push_back(products[j]);
			}

			ansVec.push_back(vecAns);
		}

		return ansVec;
	}
};
```
我果真不适合写题解，写文章啊！