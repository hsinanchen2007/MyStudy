![image.png](https://pic.leetcode-cn.com/d08f2a81d0f5c4bacadba2fb6a825cfa61be90063f417db5dcb5949f4f937340-image.png)

```python []
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        ans, ins = [0] * len(nums), []  #插排数组初始化
        for t, c in enumerate(nums[:: -1], 1):  #逆序遍历
            k = bisect.bisect_left(ins, c)      #二分查找
            ins[k: k] = [c]             #插入
            ans[-t] = k                 #逆序输出答案
        return ans
```

一种用了队列一种没有，不过插入语句再快也是快不过赋值语句的。

```python []
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        ans, ins = collections.deque(), []  #插排数组初始化
        for c in nums[:: -1]:               #逆序遍历
            k = bisect.bisect_left(ins, c)
            ins[k: k] = [c]
            ans.appendleft(k)
        return ans
```
