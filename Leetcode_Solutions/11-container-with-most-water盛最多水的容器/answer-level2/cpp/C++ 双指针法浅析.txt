首先放代码
```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0, start = 0, end = height.size() - 1;
        while(start < end){
            area = max(area, (end - start)*min(height[start], height[end]));
            if(height[start] < height[end]) start ++;
            else end --;
        }
        return area;
    }
};
```
对于这个方法，官方写的算比较清楚了，这里我留一下自己的理解
1. 为什么高度较小移动不会错过最优解
因为如果最优面积以高度较小的部分为边，那么对应的宽度肯定不会超过未移动前的宽度
比如现在两条边分别是i h1 和 j h2
那么面积为(j - i)*min(h1, h2)
若最优解以min(h1, h2)为边，另一条边为k h3
则面积为(k - i) * min(h1, h2, h3) < (j - i) \*min(h1, h2)
产生了矛盾，所以高度较小的边舍去并不会妨碍最优解的寻找