看到首页没有C++的解法，翻到第二页有一个看不太懂的解法（原作者太熟练，各种简洁写法），所以我就结合官方题解给出一个C++的解法
```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0, l = 0, r = height.size()-1;
        while(l<r){
            result = max(result,min(height[l],height[r])*(r-l));
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
    return result;
    }
};
```
函数部分第一行表示定义双指针，第三行就是算面积。
后面if判断的原理就是：如果你这根较长（比如l>r)，那么你动l也没用，因为肯定是按照短一点的算高度，反而还会减少宽度，所以比较左右两边高度后
修改较短的位置即可。
