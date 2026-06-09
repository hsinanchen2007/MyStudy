![image.png](https://pic.leetcode-cn.com/8688905efb7a4dc11c500bf61010f978fe9ed5aa418066ee65525bd4887242c7-image.png)
解题思路：遍历输入字符串，若等于'.'删除。若等于'+'，标记并计数，若等于'@'则删除之间的字符。
```
int numUniqueEmails(vector<string>& emails) {
	set<string> res; int count = 0; int tmp = 0;
	for (int i = 0; i<emails.size(); ++i)
		for (int j = 0; j<emails[i].size(); ++j) {
			if (emails[i][j] == '@') break;
			if (emails[i][j] == '.') {
				emails[i].erase(j, 1); continue;
			}
			if (emails[i][j] == '+') {
				tmp = j;
				while (emails[i][j] != '@') {
					count++; ++j;
				}
				emails[i].erase(tmp, count);
				count = 0;  break;
			}
		}
	for (auto itm : emails)
		res.insert(itm);
	return res.size();
}
```
