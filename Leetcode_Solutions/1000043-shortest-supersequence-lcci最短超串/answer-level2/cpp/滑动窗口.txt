### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
		vector<int> result;
		if (big.size() < small.size() || small.size() <= 0) { return result; }
		map<int, int> buff;
		for (auto& sm : small) { buff[sm] = 0; }
		int i = 0,j = 0,nilen = INT_MAX-1;
		while (i < big.size() && j < big.size()) {
			while (j < big.size() && !right(buff,small)) {
				buff[big[j]] += 1;
				j++;
				
			}
			while (i <= j && right(buff, small)) {
				buff[big[i]] -= 1;
				i++;
			}
			auto len = j - i + 1;
			if (i > 0 && small.size() <= len && len < nilen) {
				nilen = len;
				if (result.size() <= 0) { result.push_back(0); result.push_back(0); }
				result[0] = i-1; result[1] = j-1;
			}
		}

		return result;
	}
private:
	bool right(map<int, int>& m,vector<int> &smal) {
		for (auto &sm:smal) {
			if (m[sm] <= 0) { return false; }
		}
		return true;
	}
};
```