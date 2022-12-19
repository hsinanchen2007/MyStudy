## 思路一：暴力遍历（超时）
从左到右遍历，每次以当前矩形 i 为右边界，然后 j 从 [0, i]范围内求出最小高度minH，最后用 底 X 高 计算[j, i]构成的最大矩形面积。

### 代码
时间复杂度：O(n^2)
```c++
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        int res = 0;
        for (int i = 0; i < size; ++i) {
            int minH = heights[i];
            for (int j = i; j >= 0; --j) {
                minH = min(minH, heights[j]);
                res = max(res, (i - j + 1) * minH);
            }
        }
        return res;
    }
};
```

## 思路二：分治法
见官方思路

### 代码
时间复杂度：O(nlogn)
空间复杂度：O(n)
```c++
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        return helper(heights, 0, size-1);
    }
    int helper(vector<int>& heights, int start, int end) {
        if (start > end) {
            return 0;
        }
        int mid = start;
        for (int i = start; i <= end; ++i) {
            if (heights[i] < heights[mid]) {
                mid = i;
            }
        }
        return max((end - start + 1) * heights[mid], max(helper(heights, start, mid - 1), helper(heights, mid + 1, end)));
    }
};
```

## 思路三：栈
遍历高度，求出每个**以当前柱子为高**的最大矩形面积，需要向左右遍历，找出可以向左右扩展的最大宽度（即左右两边第一个小于当前柱子的高度的柱子），向左右扩展的时间复杂度为O(n)，为了降低复杂度，通过使用递增单调栈来找右边第一个小于当前柱子高度的柱子而不用找左边，这样以栈顶元素的柱子为高度的左边界就是本身，而右边界为第一个小于栈顶的元素。如下图：

```
以柱子 i 为高度的最大矩形左右边界满足：
l: 左边第一个高度 h[l] < h[i].
r: 右边第一个高度 h[r] < h[i]
矩形面积: i * (r - l - 1)
```

![image.png](https://pic.leetcode-cn.com/743f7ce6fff6d5327b2a2ea6cdd4d7fcb4bf81d7b8d19e8713a8f0292defcd13-image.png)


- i = 0，栈为空，直接将栈顶元素的下标放入栈中，当前栈元素 [0]；
- i = 1，栈不为空并且当前柱子高度小于栈顶元素柱子高度，则找到以栈顶元素高度为左边界（左边都小于栈顶元素高度），当前元素为右边界（第一个小于栈顶元素），弹出栈顶元素并计算此时最大矩形面积 = 高 X 宽度 = 2 * 1 = 2，入栈当前元素下标 1，当前栈元素 [1]；
- i = 2，大于栈顶元素高度直接入栈，当前栈元素 [1, 2]；
- i = 3，大于栈顶元素高度直接入栈，当前栈元素 [1, 2, 3]；
- i = 4, 小于栈顶元素，则找到以栈顶元素高度为左边界，当前元素为右边界，弹出栈顶元素并计算此时最大矩形面积 = 6 * 1，当前栈元素 [1, 2]；i = 4 的高度仍然小于栈顶元素，同样，找到以栈顶元素高度为左边界，当前元素为右边界，弹出栈顶元素并计算此时最大矩形面积 = 5 * 2， 退出循环，入栈当前下标 4 ，当前栈元素 [1, 4]；
- i = 5，大于栈顶元素高度直接入栈，当前栈元素 [1, 4, 5]；
- i = 6（虚拟柱子高度0），依次弹出栈顶元素并计算以弹出的栈顶元素为高度的最大面积。

### 代码
时间复杂度：O(n)
```c++
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {        
        stack<int> st;
        heights.push_back(0);//结尾虚拟柱子高度0
        int size = heights.size();
        int res = 0;
        for (int i = 0; i < size; ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int val = st.top();
                st.pop();
                res = max(res, heights[val] * (st.empty() ? i : (i - st.top() - 1)));//宽度不包含当前元素
            }
            st.push(i);
        }
        return res;
    }
};
```


