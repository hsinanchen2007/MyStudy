```
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        count=[arr.count(i) for i in set(arr)]
        return len(count)==len(set(count))
```
![捕获.JPG](https://pic.leetcode-cn.com/e477b76a9e56782c7d5cc1e5e270fd1d08dbec2f7ccd40ce75405623ffe6f570-%E6%8D%95%E8%8E%B7.JPG)

