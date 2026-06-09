### 解题思路
两个数组保存每个字母出现的次数,再一比较完事
执行用时 :4 ms, 在所有 C 提交中击败了96.53%的用户
内存消耗 :7.7 MB, 在所有 C 提交中击败了89.09%的用户

### 代码

```c
int canConstruct(char * ransomNote, char * magazine) {
	int ran[33] = { 0 };
	int mag[33] = { 0 };
	while (*ransomNote) {
		ran[*ransomNote - 'a']++;
		ransomNote++;
	}
	while (*magazine) {
		mag[*magazine - 'a']++;
		magazine++;
	}
	for (int i = 0; i < 33; i++) {
		if (ran[i] > mag[i])
			return 0;
	}
	return 1;
}
```