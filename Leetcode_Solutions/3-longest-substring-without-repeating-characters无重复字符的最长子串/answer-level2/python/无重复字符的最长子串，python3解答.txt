### 解题思路

拿到这道题，最直接的感觉就是顺着来呗，一个一个循环下去查找，如果有重复的就停止，计算长度。

最后提交的时候，报错，发现没有考虑到长度为1的情况，因此就加上了。

我这种方案应该是最容易想到，但是在操作过程中，如果对长度计算和索引操作引起的超出索引范围等类似问题感到头疼的宝宝（比如我），还是要多想想哦~

### 代码

```python3

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 1:
            return 1
        else:
            l_list = []
            for j in range(len(s)-1):
                ss = s[j:]

                i = 0
                n_list = []
                while ss[i] != ss[i+1] and ss[i+1] not in n_list:

                    n_list.append(ss[i])
                    if i+1 >= len(ss)-1: 
                        break
                    i += 1

                l_list.append(len(n_list)+1)

            return max(l_list)


```