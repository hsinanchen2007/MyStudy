### 解题思路
此处撰写解题思路
![2020-04-02 17-53-05 的屏幕截图.png](https://pic.leetcode-cn.com/a86c7504ae7faefa447a8b57b24209d20a1ed82f839a96543e831cc4fbe0dfb0-2020-04-02%2017-53-05%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

### 代码

```cpp
class Solution {

public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();

        if (!N) {
            return 0;
        }

        stack<int> mStack;
        mStack.push(0);
        int ans = heights[0];

        for (int i = 0; i < N; i++) {

            while (!mStack.empty() && heights[i] <= heights[mStack.top()]) {
                auto height = heights[mStack.top()];
                mStack.pop();
                int weight = mStack.empty() ? i : i - mStack.top() - 1;
                ans = max(ans, height * weight);
            }
            mStack.push(i);
        }

        while (!mStack.empty()) {
            auto height = heights[mStack.top()];
            mStack.pop();
            int weight = mStack.empty() ? N : N - mStack.top() - 1;
            ans = max(ans, height * weight);
        }
        
        return ans;
    }
};
```