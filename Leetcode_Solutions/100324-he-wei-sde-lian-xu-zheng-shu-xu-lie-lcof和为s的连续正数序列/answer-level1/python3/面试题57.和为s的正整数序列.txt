### 解题思路
- 设序列的第一元素为n1,序列长为n,和为t
- 如果能成功构造连续序列的话一定满足等差公式，整理得n1 = （a）/（b）,a=2*t-n^2+n
- n的取值范围（2,end）,end是假设n1=1时，等比公式解出的n
- 遍历n,判断n1是不是正！整数！
- 是则构造序列，不是则继续循环

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        res = []
        for n in range(2,int((2*target)**0.5)+1):
            if (2*target-n**2+n)%(2*n)==0 and (2*target-n**2+n)/(2*n)>0:
                n1 = (2*target-n**2+n)//(2*n)
                res.append([x for x in range(n1,n1+n)])
            else:continue
        res.sort()
        return res
            

```