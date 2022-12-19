### 解题思路
官方的题解是直接记录修改的nums作为新排列，我是用了一个新的vector来保存每次的排列。
思路是一样的，用回溯法，从0~n-1确定每个位置上的数，当回溯到这一层时把这个数依次与后面的数交换，再进入递归。

### 代码

```cpp
class Solution {
private:
	vector<vector<int>>res;//用来保存最后的结果
	vector<int>nums;//输入的数据
	vector<int>path;//保存当前的排列

public:
	void DFS(int t) {
		path.push_back(nums[t]);
		if (t == nums.size()-1) {//满了就记录下这个排列
			res.push_back(path);
			return;
		}

		for (int i = t; i < nums.size(); i++) {
			//i=t开始往后让nums[t]与nums[i]交换
			//当i=t时相当于没有交换，所以可以写在一起
			swap(nums[t], nums[i]);

			//因为交换后nums[t]的值改变了，所对应path的最后一个值要等于为新的num[t]
			path.pop_back();
			path.push_back(nums[t]);

			DFS(t + 1);
			path.pop_back();

			//回溯回来后再交换回去
			swap(nums[t], nums[i]);
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		this->nums = nums;
		DFS(0);
		return res;
	}

};
```