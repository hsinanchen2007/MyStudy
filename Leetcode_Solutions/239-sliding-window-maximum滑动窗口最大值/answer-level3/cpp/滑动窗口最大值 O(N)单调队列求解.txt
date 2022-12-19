# 解题思路
在解题之前，需要先理解[单调队列](https://blog.csdn.net/qq_35976351/article/details/103396522)。单调队列是一个双端队列，元素从队尾进入，从队尾或者队首弹出。从队首到队尾元素是严格递增或者递减的。这样，如果需要最大值或者最小值，直接从队首获取即可。

滑动窗口问题，是一种变形的动态规划问题，核心是**求解出最值存在的条件**。以题目的例子：
[1,3,-1,-3,5,3,6,7]
我们发现，之后元素是单调递减的时候，后一个元素才有可能是窗口的最值，否则永远不会是最值。给个例子，假设窗口长度事3：
[1 2 3] x... 
当前最值是3， 窗口移动的时候，2不可能是最值，因为后面有3存在，而且不论x是什么，2都不可能是最值。
对于序列：
[3, 2, 1, x]
在没有遍历到x的时候，2和1都可能是最值，因此都要保留在队列中。x加入的时候，需要队列元素构成递减才行，即如果大于队尾元素，则队尾元素一直弹出。

**根据上述，我们需要维护一个单调队列，然后加入新元素并弹出过期元素**

# 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> res;
        int N = nums.size();
        if (k <= 0 || N <= 0 || N < k) {
            return res;
        }
        std::deque<int> dq;
        for (int i = 0; i < N; ++i) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (dq.front() == i - k) { // 队首元素过期
                dq.pop_front();
            }
            if (i >= k - 1) {  // 加入未过期的队首元素，最值
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
```