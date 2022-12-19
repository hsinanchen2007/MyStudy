###
解题思路
###
我的方法用时用时比较久，跟官方的解法不一样，先通过排序将小的都放在A，大的都放在B，最后将B添加到A末尾
i和j分别是A和B的指针
i从前往后，j从后往前，将大的放在B，小的放在A，即A[i] > B[j]就交换位置，然后再在当前位置继续循环一次，两层循环结束，A里都是比B小的，将B数据全部添加在A末尾

```python 3
class Solution(object):
    def merge(self, A, m, B, n):
        """
        :type A: List[int]
        :type m: int
        :type B: List[int]
        :type n: int
        :rtype: None Do not return anything, modify A in-place instead.
        """
        # i从前往后，j从后往前，将大的放在B，小的放在A，交换位置后，在当前位置继续循环一次，
        # 两层循环结束，A里都是比B小的，将B数据全部添加在A末尾
        i = 0
        while i < m:
            for j in range(n - 1, -1, -1):
                if A[i] > B[j]:
                    A[i], B[j] = B[j], A[i]
                    i = i - 1
                    break
            i += 1
        A[m:] = B
```


