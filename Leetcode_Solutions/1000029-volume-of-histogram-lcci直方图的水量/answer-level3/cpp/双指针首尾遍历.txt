### 解题思路
其实我也不知道叫啥，暂且叫做双指针首尾遍历，存储首尾最大值，小的一边启动遍历，遇到大于的更新最大值，并记录差值进temp，进入下一个循环。
还有提升空间，共勉之。

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        if (!height.size()) return 0;
        int left = 0;
        int right = height.size()-1;
        int leftMax = height[left];
        int rightMax = height[right];
        int temp = 0;
        for(;left < right;)
        {
            if(height[left] < height[right])
            {
                if(leftMax > height[left+1])
                {
                    temp += leftMax - height[left+1];
                }
                else
                {
                    leftMax = height[left+1];
                }
                left++;
            }
            else
            {
                if (rightMax > height[right -1])
                {
                    temp += rightMax - height[right -1];
                }
                else
                {
                    rightMax = height[right-1];
                }
                right--;
            }
        }
        return temp;
    }
};
```