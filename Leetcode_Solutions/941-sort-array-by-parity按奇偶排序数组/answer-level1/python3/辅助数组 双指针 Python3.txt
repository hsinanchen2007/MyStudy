**思路：**

没有空间复杂度要求的话，可以开两个数组，一个存储偶数，另一个存储奇数，然后一边遍历原数组一边统计，遍历后把偶数数组和奇数数组连接起来输出即可。

如果要求不另开数组，在原数组上操作的话，那么需要用双指针遍历。双指针遍历有两种方法：一种是双指针同向遍历，初始状态都指在数组左端，后面指针不断加一，遇到偶数就交换到前面去，再把前面指针加一，指导后面指针遍历完数组结束；另外一种是双指针相向遍历，初始状态是第一个指针指在数组左端，第二个指针指在数组右端，当两个指针没有相遇时，右边指针向左寻找偶数，左边指针向右寻找奇数，然后交换指针所指的两个元素，直到两个指针相遇为止。

时间复杂度 $O(N)$

空间复杂度 $O(1)$

**图解：**

![图解](https://pic.leetcode-cn.com/1f16294e2d6893529a3d49ee620c7d103f6cdcc319a796ab46a77911dffb8cd8.gif)


**代码：**

有辅助数组的算法

```python
class Solution:
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        ans1 = []
        ans2 = []
        for i in A:
            if i % 2 == 0:
                ans1.append(i)
            else:
                ans2.append(i)
        return ans1 + ans2
```

双指针同向遍历

```python
class Solution:
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        i = 0
        for j in range(len(A)):
            if A[j] % 2 == 0:
                A[i], A[j] = A[j], A[i]
                i += 1
        return A
```

双指针相向遍历

```python
class Solution(object):
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        
        l = len(A) 
        i, j = 0, l-1
        while i < j:
            while A[i] % 2 == 0 and i < j:
                i += 1
            while A[j] % 2 == 1 and i < j:
                j -= 1
            A[i], A[j] = A[j], A[i]
                    
        return A
```