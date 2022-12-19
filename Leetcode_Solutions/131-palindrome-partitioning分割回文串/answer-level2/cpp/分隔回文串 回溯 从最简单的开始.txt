采用回溯的思想，找不同的子串
关键并不是一个个向上添加的，而是用下标来控制
一个lastindex表示上一个已经添加进去的回文串结束的位置，当前可以从lastindex下标开始，取i在[lastindex, length()-1]之间的片段，判断是回文串的话就添加到cur里，然后修改lastindex向下递归

```
class Solution {
public:
	vector<vector<string>>ans;
	bool isok(string s) {
		int length = s.length();
		int i = 0, j = length - 1;
		while (i < j && i < length && j>0)
		{
			if (s[i] != s[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
	void backtrack(string s, vector<string>cur, int lastindex) {
		int n = s.length();
		if (lastindex >= n)
		{
			ans.push_back(cur);
			return;
		}
		for (int i = lastindex; i < n; i++) {
			string stemp = s.substr(lastindex, i - lastindex + 1);
			if (isok(stemp))
			{
				cur.push_back(stemp);
				backtrack(s, cur, i + 1);
				cur.pop_back();
			}
		}
	}
	vector<vector<string>> partition(string s) {
		vector<string>cur;
		backtrack(s, cur, 0);
		return ans;
	}
};
```
