```
#问题关键是找出嵌套深度与赋值之间的关系
#若深度为奇数，赋值为0；为偶数，赋值为1 计算左边'('的个数
class Solution:
    def maxDepthAfterSplit(self, seq: str):
        pre = 0
        res = [0 for _ in range(len(seq))]
        cnt = []
        for i,ch in enumerate(seq):
            if ch == '(':
                cnt.append(i)
            else:
                j = cnt.pop()
                if len(cnt)==0:
                    continue
                else:
                    if len(cnt)%2 == 1:
                        res[i]=1
                        res[j]=1
        return res
print(Solution().maxDepthAfterSplit("()((()))()"))
```
