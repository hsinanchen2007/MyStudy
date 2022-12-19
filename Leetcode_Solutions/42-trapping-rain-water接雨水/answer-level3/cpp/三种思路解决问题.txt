### 解题思路
![image.png](https://pic.leetcode-cn.com/725ce9165ad3c306ede72feec7d302e146ade9dad2f07dd92e04e64cdf6c931f-image.png)

### 代码

```cpp
class Solution {
public:
    //左右最大值解法
    int doubleMax(vector<int>& height)
    {
        int size = height.size();
        if(size < 3) return 0;
        int ans = 0;
        vector<int> left_max(size, height[0]);
        vector<int> right_max(size, height[size - 1]);
        for(int i = 1; i < height.size(); i++)
            left_max[i] = max(left_max[i - 1], height[i]);
        for(int i = size - 2; i >= 0; i--)
            right_max[i] = max(right_max[i + 1], height[i]);
        for(int i = 1; i < size - 1; i++)
            ans += min(right_max[i], left_max[i]) - height[i];
        return ans;
    }
    //辅助栈解法
    int helpStack(vector<int>& height)
    {
        stack<int> stk;
        int ans = 0;
        for(int i = 0; i < height.size(); i++)
        {
            while(!stk.empty() && height[i] > height[stk.top()])
            {
                int base = stk.top();
                stk.pop();
                if(stk.empty()) break;
                ans += (i- stk.top() -1) * (min(height[i], height[stk.top()]) - height[base]);
            }
            stk.push(i);
        }
        return ans;
    }

    //双指针解法
    int doublePointer(vector<int>& height)
    {
        int ans = 0, left_max = 0, right_max = 0;
        int left = 0, right = height.size() - 1;
        while(left < right)
        {
            if(height[left] < height[right])
            {
                if(height[left] > left_max) left_max = height[left];
                else ans += min(left_max, height[right]) - height[left];
                left ++;
            }
            else
            {
                if(height[right] > right_max) right_max = height[right];
                else ans += min(right_max, height[left]) - height[right];
                right --;
            }
        }
        return ans;
    }
    int trap(vector<int>& height) {
        //左右最大值解法
        // return doubleMax(height);

        //辅助栈解法
        // return helpStack(height);

        //双指针解法
        return doublePointer(height);
        
    }
};
```