### 解题思路
考点：二分查找
思路：双指针中的首尾指针法，所谓盛最多水的容器，就是max{矩形的面积}。而矩形的宽是(right-left)，矩形的高是什么呢？根据“木桶原理”，高是左右两根柱子中最矮的那一个。那从0到left=right，我们计算矩形面积，每次需要保存的是矩形面积的最大值。
即： res = max(res,(right - left)*min(height[left],height[right]));
left和right的更新依据他亮的高度大小比较，因为求的是最大面积，所以左边小就更新左边，右边小就更新右边。

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 0)
        {
            return 0;
        }
        int left = 0;
        int right = height.size()-1;
        int res = 0;

        while(left < right)
        {
            res = max(res,(right - left)*min(height[left],height[right]));
            if(height[left] <= height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return res;
    }
};
```