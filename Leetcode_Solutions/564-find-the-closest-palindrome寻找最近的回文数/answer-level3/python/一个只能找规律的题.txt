### 解题思路
边界情况还挺多，只能说要是实际考试面试遇到了，我肯定来不及改好……

### 代码

```python3
class Solution:
    def nearestPalindromic(self, n: str) -> str:
        if int(n)==0:
            return "1"
        elif int(n)<=10:
            return str(int(n)-1)
        elif n=="11":
            return "9"
        # mid: 分割点
        mid=(len(n)+1)//2
        # rlen: 分割点之后需要补齐的数字位数
        rlen=len(n)-mid
        # lefts: 装载所有可能的左半部分：-1，本身，+1
        lefts=[]
        left = int(n[:mid])
        for i in range(-1,2):
            lefts.append(str(left+i))

        # 补上回文数的右边
        res=[]
        for lstr in lefts:
            if len(lstr)<rlen:
                # 退位情况经测试发现就是得这么写
                res.append((lstr+lstr[-1]+lstr[:rlen-1][::-1]))
            else:
                # 正常情况
                res.append(lstr+lstr[:rlen][::-1])
        # 把n本身剔除
        res=[int(i) for i in list(set(res)-set((n,)))]
        # 把差值加上，排序，返回差值最小的
        res=[[abs(int(r)-int(n)), r] for r in res]
        res.sort()
        return str(res[0][1])
```