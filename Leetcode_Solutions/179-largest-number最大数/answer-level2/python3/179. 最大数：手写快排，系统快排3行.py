核心比较点就是两者结合时谁大谁放在前面，最后数字结合起来以后要对左侧的0进行处理，两种方法里面手写版比较快，系统快排慢一点点但是比较好写。

![image.png](https://pic.leetcode-cn.com/78bfdd8fc8860d0ea907cfbde246d9dea1cd0d9497629f9e8669c92738465d56-image.png)


手写：

```py
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums = [*map(str, nums)]
        def qsort(i, j):
            if i + 1 < j:
                mid = nums[(i + j) // 2]
                l, m, r = [], [], []
                for num in nums[i: j]:
                    if num + mid > mid + num:
                        l += [num]
                    elif num + mid < mid + num:
                        r += [num]
                    else:
                        m += [num]
                nums[i: j] = l + m + r
                qsort(i, i + len(l))
                qsort(j - len(r), j)
        qsort(0, len(nums))
        ans = ''.join(nums).lstrip('0')
        return ans if ans else '0'
```

系统快排需要调入functools模块更改系统对比函数，对比函数比较短，直接用匿名函数就行：

```py
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        import functools
        ans = ''.join(sorted([*map(str, nums)], key = functools.cmp_to_key(lambda x, y: -1 if x + y > y + x else 1))).lstrip('0')
        return ans if ans else '0'
```
