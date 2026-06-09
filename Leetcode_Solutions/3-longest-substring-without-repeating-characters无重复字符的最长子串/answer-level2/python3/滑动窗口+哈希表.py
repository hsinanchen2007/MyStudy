**基本思路**：给定一个字符串，求最长无重复子串的长度。无重复意味着我们可以采用哈希表来存储，计算字串的长度意味可以采用双指针或滑动窗口的方法求解。算法如下：

1. 定义一个哈希表用于存储遍历过的字符的位置：hash[s[i]] = index
2. 定义滑动窗口的左指针，用于指示当前无重复字串的起始位置
3. 遍历字符串，若字符在哈希表中出现，则按照最大值原则更新左指针: ```
left = max(left, hash[s[i]]+1)
```
同时，更新哈希表中该字符的下标
4. 每一次遍历都计算当前的最长无重复字串的长度：result = max(result, i-left+1)
5. 遍历完成后返回result

```python
def maxLengthOfSeq(s):
    hash_s = {}
    left = 0
    result = 0
    for i in range(len(s)):
        if s[i] in hash_s:
            left = max(left, hash_s[s[i]]+1)
        hash_s[s[i]] = i
        result = max(result, i - left + 1)
    return result
```
