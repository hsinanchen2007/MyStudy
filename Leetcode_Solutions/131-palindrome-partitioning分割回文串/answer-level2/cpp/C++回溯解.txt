### 解题思路
![image.png](https://pic.leetcode-cn.com/0638ed636460a1dc7166ca6bbc888ef47913433738cb325ea43d429c5ccd25de-image.png)
最普通的回溯，判断回文没有用DP
### 代码

```cpp
class Solution {
public:
	vector<vector<string> > result;
	vector<string > temp;
	string str;
	bool isHuiWen(int start, int end) {
		int left = start, right = end;
		while (left < right) {
			if (str[left++] != str[right--]) return false;
		}
		return true;
	}
	void dfs(int level, int deepth) {
		if (level == deepth) {
			result.push_back(temp); 
			return;
		}
		for (int i = level; i < deepth; i++) {
			if (!isHuiWen(level, i)) {
				continue;
			}
			temp.push_back(str.substr(level, i - level + 1)); 
			dfs(i + 1, deepth);
			temp.pop_back();
		}
	}
    vector<vector<string> > partition(string s) {
    	if (s.size() <= 0) return result;
    	this->str = s;
        dfs(0, s.size());
        return result;
    }
}; 
```