1.第一层循环，把字符串向右移动k个位置。

2.第二层循环，移动后的字符串，与原来字符串依次对比。当相同的位数大于等于k时，满足条件。
重复的情况用字典或者哈希表避免。

![A.png](https://pic.leetcode-cn.com/1225ce382abd42a9f3442d220cd499bdec5f5ce86fcfc0cdcb09777c3f9d25bb-A.png)

```
    def distinctEchoSubstrings(self, text: str) -> int:
        res ={}

        for k in range(1,len(text)):
            counts = 0
            for j in range(len(text)-k):
                if text[j+k] == text[j]:
                    counts = counts+1
                    if counts>=k:                       
                        res[text[j-k+1:j+k+1]] = 0
                        counts = counts-1
                else:
                    counts =0
        return len(res)
```
