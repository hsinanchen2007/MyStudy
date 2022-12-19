![QQ图片20200319180233.png](https://pic.leetcode-cn.com/a62640eaa2594449fadd283f4a88bfc3d6662e8d73f14f8e8d8afef6c84366e7-QQ%E5%9B%BE%E7%89%8720200319180233.png)

使用哈希表进行字符出现数量的统计，再遍历字符串计算，若出现过奇数数量的字符则标记，最后总数量加1

```
int longestPalindrome(string s) {
	if (s.empty()) return 0;
	unordered_map<char, int> m;
	int cnt = 0;
	bool flag = false;
	for (auto c : s)
		++m[c];
	for (auto c : s) {
		if (m[c] % 2 == 1 && !flag) flag = true;
		while (m[c] >= 2) {
			cnt += 2;
			m[c] -= 2;
		}
	}
	if (flag) cnt += 1;
	return cnt;
}
```

时间复杂度为O(n)