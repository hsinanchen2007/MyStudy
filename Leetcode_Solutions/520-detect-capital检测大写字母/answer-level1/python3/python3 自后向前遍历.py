### 解题思路
将word最后一位作为标志位，然后从倒数第二位开始自后向前遍历。
时间复杂度：O(n)
空间复杂度：O(1)

### 代码

```python3
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        s = word[-1]
        first = s>='A' and s<='Z'
        if first:
            for s in word[-2::-1]:
                if s >='a' and s<='z':
                    return False
        else:
            for i in range(len(word)-1,-1,-1):
                if word[i] >='A' and word[i]<='Z' and i!=0:
                    return False
        return True

```