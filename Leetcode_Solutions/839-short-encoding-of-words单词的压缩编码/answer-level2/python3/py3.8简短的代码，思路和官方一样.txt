### 解题思路
更加简洁，:=是py3.8的新特性，支持在语句中做赋值
word一次一次消减自己后，在set中删除

### 代码

```python3
class Solution:
	def minimumLengthEncoding(self, words: List[str]) -> int:
		good=set(words)
		for word in words:
			while word:good.discard(word:=word[1:])
		return len("#".join(good))+1
```