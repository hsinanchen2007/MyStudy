### 解题思路
1，理解题意，找括号深度，然后遇到连续的（或）就划分不同集合，这里表现为0与1
2，使用^运算解决划分

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
    int n = seq.length();
	vector<int> res;
	if (n == 0)
	{
		res.push_back(0);
		return res;
	}
	int isZero = 1;//---分开平均,1^1=0,0^1=1
	for (int i = 0; i < n; i++) {
		if (seq[i] == '(') {
			isZero ^= 1;
			res.push_back(isZero);
		}
		else {
			res.push_back(isZero);
			isZero ^= 1;
		}
	}
	return res;
    }
};
```