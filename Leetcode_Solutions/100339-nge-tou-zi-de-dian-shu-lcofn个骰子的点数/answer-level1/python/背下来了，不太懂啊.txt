### 解题思路 好像恍然大悟，更新前计数数组记录的是N-1骰子正确的计数。更新后应变成N个骰子的。如果从前往后更新，前面的先变成了N次的，在后面用到时会污染到后面的答案（因为计算N次需要N-1次的较小的点数[i-6,i)），从后向前则不会存在这个问题，因为后面的初始为零，不影响结果,且计算前面的不需要后面的（只需[i-6,i)）。
此处撰写解题思路

### [代码](https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/solution/di-gui-huo-zhe-die-dai-du-ke-yi-python-and-javascr/)

```python
class Solution:
    def twoSum(self, n: int) -> List[float]:
        def diceN(n):
            if n==1:
                return [0]+[1]*6
            cnts = diceN(n-1)+[0]*6
            for i in range(6*n,0,-1):
                cnts[i] = sum(cnts[max(0,i-6):i])
            return cnts
        return filter(lambda a:a>0,list(map(lambda a: a/6**n,diceN(n))))

        
```