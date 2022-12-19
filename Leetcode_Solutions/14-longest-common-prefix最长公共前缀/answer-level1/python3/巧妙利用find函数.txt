### 解题思路
python3中的find函数，当检测字符串中是否包含子字符串str，如果包含子字符串返回开始的索引值，否则返回-1。
while循环直到返回索引值为0，说明是前缀相同。即得到我们想要的效果了。

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        prefix = strs[0]
        i = 1

        while(i<len(strs)):
            while strs[i].find(prefix)!=0:
                prefix = prefix[0: len(prefix)-1]
            i+=1
        return prefix
```