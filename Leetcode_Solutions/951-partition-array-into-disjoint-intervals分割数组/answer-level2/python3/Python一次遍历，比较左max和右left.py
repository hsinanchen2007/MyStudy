题目中要求left中每个元素都小于等于right中的最小元素，因此不难理解，只要**保证左max <= 右max**即可。

相比于官方解法，本题解只需要一次遍历，即用l_max储存左边max，r_min储存右边min，当 l_max <= r_min时，跳出循环即可。否则，继续循环。

一个直观的想法是，对于下标i而言， **l_max = max(A[:i+1]) r_min = min(A[i+1:])**，由于所求的是左边数组的最小长度，因此从左向右遍历即可。

值得注意的是，为了**减少计算量**，我们可以比较每一个A[i]，注意，此时A[i]从right转移到left。
1. 如果A[i] > l_max，则l_max = A[i]，否则不更新。
2. 如果A[i] == r_min，即原来右端最小值，那么A[i]被剔除后，需要重新计算r_min = min(A[i+1:])

代码如下：

```
class Solution:
    def partitionDisjoint(self, A: List[int]) -> int:
        l_max = A[0]
        r_min = min(A[1:])

        for i in range(1,len(A)):
            if l_max <= r_min:        # 左边最小值 <= 右边最大值，此时下标i即为左边的长度
                return i
            l_max = max(A[i],l_max)
            if A[i]==r_min:
                r_min = min(A[i+1:])
```
