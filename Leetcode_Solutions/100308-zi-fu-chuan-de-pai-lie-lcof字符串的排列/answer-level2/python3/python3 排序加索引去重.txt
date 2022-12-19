### 解题思路
此处撰写解题思路
典型的排序去重，和之前的那个有字符串重复的排列组合问题一样的解答。
有一个一行代码的，效果居然比排序去重要好。应该是题目设定了输入字符串的长度小于8，如果再大一点的化，这个不一定就更好把

### 代码

```python3
class Solution:
    def permutation(self, s: str) -> List[str]:
        return list(set(["".join(x) for x in itertools.permutations(s)]))

        # ans = []
        # s = "".join(sorted(s))

        # def helper(s,res):
        #     if not s:
        #         ans.append(res)
        #     pre = ''
        #     for i in range(len(s)):
        #         if s[i]!=pre:
        #             helper(s[:i]+s[i+1:],res+s[i])
        #         pre = s[i]
        
        # helper(s,'')
        # return ans
```