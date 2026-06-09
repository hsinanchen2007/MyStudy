### 解题思路
递增栈和递减栈的选取规则：
（1）需要找到某一个位置的左边第一个大于自身的和右边第一个大与自身的----递减栈（遇到比栈顶元素或者栈顶位置对应元素大的，就依次出栈）
（2）需要找到某一个位置的左边第一个小于自身的和右边第一个小与自身的----递增栈（遇到比栈顶元素或者栈顶位置对应元素小的，就依次出栈）

本题接雨水：
就是找到一个凹进去的地方，就是找左右比中间高的。为了方便计算长度len（我们的栈保存数组的index（下标）信息）
当前cur（凹陷）：栈顶元素对应下标---height[cur]为当前的值
左边l:为栈顶元素出战后，新的栈顶元素，stack.pop()后的stack.top(),height[stack.top()];
右边r:为当前遍历到的i，height[i];
因为会依次出栈所有比i位置小的栈内元素，所以我们只需要计算 同层高度的雨水即可，h:min(r - height[cur], l - height[cur]);
因为我们保存的下标，所以len:i - stack.top() - 1;
雨水就是 h*len;
### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        std::stack<int> stack;
        if (height.size() == 0) return 0;
        int count  = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!stack.empty() && height[stack.top()] < height[i]) {
                int cur = stack.top();
                stack.pop();
                if(stack.empty()) break;;
                int l = height[stack.top()];
                int r = height[i];
                int h = min(r - height[cur], l - height[cur]);
                int len = i - stack.top() - 1;
                count += len * h;
            }
            stack.push(i);
        }
        return count;
    }
};
```