### 解题思路
用栈存储左边更高的位置就行啦

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int res = 0;

        for (int i = 0; i < height.size(); i++) {
            while (!s.empty() && height[i] > height[s.top()]) {
                int tmp = s.top();
                s.pop();
                if (s.empty()) {
                    break;
                }
                res += (min(height[i], height[s.top()]) - height[tmp]) * (i - s.top() - 1);
            }

            s.push(i);
        }

        return res;
    }
};
```