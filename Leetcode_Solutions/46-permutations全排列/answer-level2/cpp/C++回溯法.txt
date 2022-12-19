### 解题思路
分析：利用回溯算法生成全排列即可，注意这里是给定一个数组，而不是元素个数
所以回溯的层数应该是数组长度，而元素是数组元素

### 代码

```cpp
class Solution {
public:
	vector<vector<int> > result;
	void arrange(int start, int level, int visited[], vector<int>& nums, int arr[]) {
		// 找到了一个题解
		if (start >= level + 1) {
			vector<int > temp;
			for (int i = 0; i <= level; i++) {
				temp.push_back(arr[i]);
			}
			result.push_back(temp);
			return;
		}
		// 尝试所有可能
		for (int i = 0; i <= level; i++) {
			if (visited[i]) continue;
			visited[i] = 1;
			arr[start] = nums[i];
			arrange(start + 1, level, visited, nums, arr);
			visited[i] = 0;
		}
	}
    vector<vector<int> > permute(vector<int>& nums) {
    	int vLen = nums.size();
    	// 如果只有一个元素或没有原素返回该元素自身即可 
    	if (vLen <= 1) {
    		result.push_back(nums);
    		return result;
		}
		// 防止重复访问
		int *visited = new int[vLen]();
		// 存放结果
		int *arr = new int[vLen]();
		arrange(0, vLen - 1, visited, nums, arr);
		delete[] visited, arr;
        return result;
    }
}; 
```