# 暴力法

## 思路

本题和主站239题一样。

符合直觉的想法是直接遍历 nums, 然后然后用一个变量 slideWindow 去承载 k 个元素，
然后对 slideWindow 求最大值，这是可以的，时间复杂度是 O(n \* k)


## 代码

JavaScript:

```js
var maxSlidingWindow = function(nums, k) {
  // bad 时间复杂度O(n * k)
  if (nums.length === 0 || k === 0) return [];
  let slideWindow = [];
  const ret = [];
  for (let i = 0; i < nums.length - k + 1; i++) {
    for (let j = 0; j < k; j++) {
      slideWindow.push(nums[i + j]);
    }
    ret.push(Math.max(...slideWindow));
    slideWindow = [];
  }
  return ret;
};
```
Python3:

```python
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if k == 0: return []
        res = []
        for r in range(k - 1, len(nums)):
            res.append(max(nums[r - k + 1:r + 1]))
        return res
```

**复杂度分析**
- 时间复杂度：$O(N * K)$
- 空间复杂度：$O(1)$   （JS由于使用了slicewindow其实是$O(K)$，但是这部分其实完全可以优化掉）

#  双端队列

## 思路

我们还可以用线性的时间去完成，考虑用双端队列来完成，思路是用一个双端队列来保存`接下来的滑动窗口可能成为最大值的数`。具体做法：


- 入队列

- 移除失效元素，失效元素有两种

1. 一种是已经超出窗口范围了，比如我遍历到第4个元素，k = 3，那么i = 0的元素就不应该出现在双端队列中了
具体就是`索引大于 i - k + 1的元素都应该被清除`

2. 小于当前元素都没有利用价值了，具体就是`从后往前遍历（双端队列是一个递减队列）双端队列，如果小于当前元素就出队列`


如果你仔细观察的话，发现双端队列其实是一个递减的一个队列。因此队首的元素一定是最大的。用图来表示就是：

![](https://pic.leetcode-cn.com/690f7a5dd641265ecd066678ad411959ce2233fac2835c0be5e4b5425ee627b9.jpg)

> 实际上deque存储的是索引，为了方便看出效果，图上话的是索引对应的数值

## 关键点解析

- 双端队列简化时间复杂度

- 滑动窗口

## 代码

JavaScript:

```js
var maxSlidingWindow = function(nums, k) {
  // 双端队列优化时间复杂度, 时间复杂度O(n)
  const deque = []; // 存放在接下来的滑动窗口可能成为最大值的数
  const ret = [];
  for (let i = 0; i < nums.length; i++) {
    // 清空失效元素
    while (deque[0] < i - k + 1) {
      deque.shift();
    }

    while (nums[deque[deque.length - 1]] < nums[i]) {
      deque.pop();
    }

    deque.push(i);

    if (i >= k - 1) {
      ret.push(nums[deque[0]]);
    }
  }
  return ret;
};
```

Python3:

```python
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        deque, res, n = [], [], len(nums)
        for i in range(n):
            while deque and deque[0] < i - k + 1:
                deque.pop(0)
            while deque and nums[i] > nums[deque[-1]]:
                deque.pop(-1)
            deque.append(i)
            if i >= k - 1: res.append(nums[deque[0]])
        return res


```


**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(N)$




## 扩展

### 为什么用双端队列
因为删除无效元素的时候，会清除队首的元素（索引太小了
）或者队尾(元素太小了)的元素。 因此需要同时对队首和队尾进行操作，使用双端队列是一种合乎情理的做法。


欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)


