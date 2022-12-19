### 解题思路
此处撰写解题思路
遍历word 再遍历每个字符串，统计字符串中的字母个数与chars中个数对比，如果大于则不行，小于等于则可拼写

### 代码

```python3

class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        sum = 0
        for i in words:
            for j in i:
                if i.count(j) <= chars.count(j):
                    a = 1
                    continue#这个可加可不加，我发现加了后速度会快一点，
                            #现在是萌新 并不懂为何加了continue会更快，感觉速度应该是一样的才对。有大佬可以麻烦解释下，哈哈哈哈哈
                else:
                    a = 0
                    break
            if a==1:
                sum+=len(i)
        return sum
        # s = np.zeros(26)
        # sum = 0
        # for y in chars:
        #     s[ord(y)-97]+=1
        # for i in words:
        #     if len(chars)<len(i):
        #         continue;
        #     for x in i:
        #         ss = s.copy()
        #         ss[ord(x)-97]-=1
        #         if ss[ord(x)-97] < 0:
        #             a = 1
        #             break
        #         else:
        #             a = 0
        #     if a==1:
        #         continue
        #     else:
        #         sum = sum+len(i)
        # return(sum)        

```