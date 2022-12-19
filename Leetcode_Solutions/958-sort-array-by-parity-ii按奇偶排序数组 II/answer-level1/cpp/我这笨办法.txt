### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		vector<int> res;
		vector<int> odd,even;
		for (auto n : A) {
			if (n % 2)odd.push_back(n);
			else
			{
				even.push_back(n);
			}
		}

		for (int i = 0; i < odd.size(); i++) {
			res.push_back(even[i]);
			res.push_back(odd[i]);
		}
		return res;
	}
};
```