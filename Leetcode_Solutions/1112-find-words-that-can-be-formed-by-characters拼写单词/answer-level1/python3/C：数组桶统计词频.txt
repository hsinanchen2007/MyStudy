### 解题思路
题目要求:**注意：每次拼写时，chars 中的每个字母都只能用一次。**，就不可以用`set`解决，那么意思就是单词`word`内字母个数$\leq$`chars`内字母个数。

### 代码
+ 与每次拷贝清零零时`word`桶，还可以在比较完后清0供下次使用（虽然可以提前返回）
+ 没有python的for-else，可以手动实现。
```c
int countCharacters(char ** words, int wordsSize, char * chars){
	char char_cnt[26] = {0}, word_cnt[26] = {0};
	short i, j, word_len = 0, tmp_len;
	int len = 0;
	for (i = 0; chars[i] != '\0'; i++) char_cnt[chars[i]-97]++;  // char词频处理
	/* 1.逐个单词比较 */
	for (i = 0; i < wordsSize; i++) {
        /* 2.统计word单词词频 */
		for (j = 0; words[i][j] != '\0'; j++) {
			word_cnt[words[i][j]-97]++;  // 
		}
		/* 3.统计是否匹配 */
		word_len = j;  // 先存word长度，如果匹配就直接计数(j超界到\0就是长度)
		tmp_len = 0;  // 用于检测匹配长度然后与word_len比较
		for (j = 0; j < 26; j++) {  // 这里可以提前返回，但是要把后面的清零(否者只能拷贝数组)
			if (word_cnt[j] <= char_cnt[j])
				tmp_len += word_cnt[j];
            word_cnt[j] = 0;  // 因用同一个，用完清零
		}
		len += tmp_len == word_len ? word_len : 0;  // 4.查看是否相等(类似for_else循环)
	}
	return len;
}
```
当然不造轮子，使用`Counter`的`&`运算，然后比对与原来是否相同也是可行的（效率比for低）。

```python3 []
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        from collections import Counter
        return sum(len(word) for word in words
            if Counter(word) & Counter(chars) == Counter(word))
```

