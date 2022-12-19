### 解题思路
老习惯了，遇到排列组合的题总是想着先用回溯，没想到通过了，还是双100%。。。
![image.png](https://pic.leetcode-cn.com/6ca6e86ed8327872cf0e91c8dadcf5b59dfd4019b09fd7dc809a59e800b065c6-image.png)


### 代码

```cpp
class Solution {
public:
	vector<vector<int>>vv;
	void TraNum(vector<int>&num,vector<int>&v, int i, int n) {
		if (i == n) {
			vv.push_back(v);
			return;
		}
		v.push_back(num[i]);
		TraNum(num, v, i + 1, n);
		if (i + 1 < n &&num[i]!=0&& (num[i] * 10 + num[i + 1]) < 26) {
			v.pop_back();
			v.push_back(num[i] * 10 + num[i + 1]);
			TraNum(num, v, i + 2, n);
		}
	}
	int translateNum(int num) {
		if (num == 0)return 1;
		int size = 0,tmp=num;
		while (num > 0) {
			size++;
			num /= 10;
		}
		vector<int>nums(size);
		int n = size;
		while (tmp > 0) {
			nums[--size] = tmp % 10;
			tmp /= 10;
		}
		vector<int>v;
		TraNum(nums, v, 0, n);
		return vv.size();
	}
};
```