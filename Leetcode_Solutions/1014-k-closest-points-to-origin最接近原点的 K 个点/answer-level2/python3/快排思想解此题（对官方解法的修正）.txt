基本思想就是利用快速排序中的partition函数，我们不需要对数组进行完全排序，只要找到一个支点，在这个支点前面的数都小于它，后面的数都大于它
，当这个支点恰好在位置K时，则前面的K个数就是我们需要的答案。
下面的伪快速排序可以帮助理解这种思想：
![image.png](https://pic.leetcode-cn.com/5c413d8361da5a3762bdb08dadaf6ea52366fb74a0ebe83e871b0dff8bae046e-image.png)

官方题解中给出的示例是不正确的实现，修正后的python实现如下：

```Python
class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        dist = lambda i: points[i][0]**2 + points[i][1]**2

        def Partition(L, left, right, K):
            if left >= right:
                return

            origin_left, origin_right = left, right
            pivot_index = random.randint(left, right)
            pivotval = L[pivot_index]

            # swap left and pivot
            L[left], L[pivot_index] = L[pivot_index], L[left]
            pivotkey = dist(left)

            while left < right:
                while left < right and dist(right) >= pivotkey:
                    right -= 1
                L[left] = L[right]
                while left < right and dist(left) <= pivotkey:
                    left += 1
                L[right] = L[left]

            L[left] = pivotval

            if K <= left - origin_left + 1:
                Partition(L, origin_left, left, K)
            else:
                Partition(L, left + 1, origin_right, K-(left - origin_left + 1))
            return

        Partition(points, 0, len(points) - 1, K)
        return points[:K]
```
