### 解题思路
动态规划，i为左边坐标，j为右边坐标，从两边开始向中间遍历，定义最大值为height[i],height[j]中小值和坐标差的乘积。height[i],height[j]中小的一边坐标值++或者--

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int Max = 0;
        int i = 0, j = n - 1;
        while(i < j){
            Max = max(Max,min(height[i], height[j]) * (j - i));
            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return Max;
        
    }
};
```