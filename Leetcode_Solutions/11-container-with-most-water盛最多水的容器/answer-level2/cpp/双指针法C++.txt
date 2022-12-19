### 解题思路
自己想了半天的动态规划，结果没有写出来。参考了别人的双指针法，确实ok，先暂时死记着吧，这道题就是需要这样干。

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        while (left < right) {
            int area = (right - left) * min(height[left], height[right]);
            max_area = max(max_area, area);

            if (height[left] < height[right]) {
                left += 1;
            }
            else {
                right -= 1;
            }
        }

        return max_area;
    }
};
```
![微信截图_20200222180405.png](https://pic.leetcode-cn.com/9302633efb2a61cb2c29c8f5c2658781314016129d01fbf4e7ceffa31cf60987-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200222180405.png)
