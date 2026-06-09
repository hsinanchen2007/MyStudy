```python
class Solution:
	def findSubstring(self, s, words: List[str]) -> List[int]:
		words_hash = collections.defaultdict(int)
		for word in words: 
			words_hash[word] += 1
		if s == '' or words == []: return []
		win_size = len(words) * len(words[0])
		# corner case
		res = []
		temp_hash = collections.defaultdict(int)
		for i in range(len(s) - win_size + 1): # O(N)
			temp_hash.clear()
			flag = True
			for j in range(i, i + win_size, len(words[0])): # (N / M)
				temp_word = s[j: j + len(words[0])]
				if temp_hash[temp_word] < words_hash[temp_word]:
					temp_hash[temp_word] += 1
				else:
					flag = False
					break
			if flag: res.append(i)
		return res
```