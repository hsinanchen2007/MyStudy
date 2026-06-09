### 解题思路
（1）找到左右两边比我小的，因为是单调递增，左边第一个一定比我小，右边是遍历的当亲位置，比我下，就出栈，计算面积；
（2）因为需要所有的元素都要出栈，所以便利到最后时（等于length），变为-1，方便所有元素出栈计算面积。
### 代码

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) return 0;
        if (heights.size() == 1) return heights[0];
        int max_val = 0;
        std::stack<int> stack;
        for (int i = 0; i <= heights.size(); i++) {
            // 便利到最后，置位-1，让所有元素出栈
            int curt = (i == heights.size()) ? -1 : heights[i];
            // 必须是单调递增 所以是 <= 号
            while (!stack.empty() && curt <= heights[stack.top()]) {
                int cur = stack.top();
                stack.pop();
                int len = stack.empty() ? i : (i - stack.top() - 1); 
                max_val = max(heights[cur] * len, max_val);
            }
            stack.push(i);
        }
        return max_val;
    }
};
```