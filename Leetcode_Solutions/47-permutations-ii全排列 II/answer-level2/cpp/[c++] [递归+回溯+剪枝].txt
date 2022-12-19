### 解题思路
执行一遍看打印的输出，秒懂Debug过程

### 代码

```cpp
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		
		vector<int> out, visited(nums.size(), 0);
		sort(nums.begin(), nums.end());
		permuteUniqueDFS(nums, 0, visited, out);
		return res;
	}
	void permuteUniqueDFS(vector<int>& nums, int level, vector<int>& visited, vector<int>& out) {
		if (level >= nums.size()) { 
			cout << "新排列：";
			for (int i = 0; i < out.size(); i++) {
				cout << out[i];
			}
			cout << endl;
			res.push_back(out); 
			return;
		}
		for (int i = 0; i < nums.size(); ++i) {
			if (visited[i] == 1) {
				printf("nums[%d]:%d之前访问过了\n",i, nums[i]);
				continue;
			}
			if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) { 
				printf("以前一个相同的元素为首的遍历结束，下一个相同数字不必再做重复工作，跳过num[%d]:%d\n", i, nums[i]);
				continue;
			}
			visited[i] = 1;
			printf("注意区分相同数字-->把num[%d]:%d放进去\n", i,nums[i]);
			out.push_back(nums[i]);
			permuteUniqueDFS(nums, level + 1, visited, out);
			printf("把num[%d]:%d抛出去\n", i,nums[i]);
			out.pop_back();
			printf("让num[%d]:%d恢复访问,visit置为0\n", i, nums[i]);
			visited[i] = 0;
		}
		return;
	}
private:
	vector<vector<int>> res;
};
```