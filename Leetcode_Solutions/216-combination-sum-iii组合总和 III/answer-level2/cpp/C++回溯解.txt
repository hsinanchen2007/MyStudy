### 解题思路
选或不选，这是个问题

### 代码

```cpp
class Solution {
public:
	int target;
	vector<int > temp;
	vector<vector<int > > result;
	// level：当前数，deepth用来限制vector大小，sum存放当前和
	void dfs(int level, int deepth, int sum) {
		// 出口条件
		if (level >= 10 || sum >= target) {
			if (sum == target && temp.size() == deepth) result.push_back(temp); 
			return;
		} 
		// 开始试探
		temp.push_back(level);
		sum += level;
		dfs(level + 1, deepth, sum);
		sum -= level;
		temp.pop_back(); 
		dfs(level + 1, deepth, sum);
	}
    vector<vector<int> > combinationSum3(int k, int n) {
    	if (k == 0 || n == 0) return result;
    	this->target = n;
        dfs(1, k, 0);
        return result;
    }
}; 
```