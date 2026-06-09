调整后的最小值和最大值,也必定是原有最小值最大值的基础上+-K。

```
class Solution:
    def smallestRangeI(self, A: List[int], K: int) -> int:
        if len(A) == 1 or max(A)-min(A)<=2*K :
            return 0;
        else :
            return max(A)-min(A)-2*K

```
![image.png](https://pic.leetcode-cn.com/9e2b9b08914e86513eaaea6b10a2c4f9e659b01f42d1954aa808505baf809bcb-image.png)

