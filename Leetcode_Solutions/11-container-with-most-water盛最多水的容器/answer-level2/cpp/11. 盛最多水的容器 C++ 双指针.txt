### 解题思路
请参考：
https://leetcode-cn.com/problems/container-with-most-water/solution/on-shuang-zhi-zhen-jie-fa-li-jie-zheng-que-xing-tu/
写的非常好

双指针：
外围两条线段构成的区域。left为左边，right为右边
为了使面积最大化，我们需要考虑更长的两条线段之间的区域。
1）**如果试图将指向较长线段的指针向内侧移动，矩形区域的面积将受限于较短的线段而不会获得任何增加。高度=短边高度， 宽度 = 原宽度-1，因此面积不会增加**
2）如果在同样的条件下，移动指向较短线段的指针尽管造成了矩形宽度的减小，但却可能会有助于面积的增大。因为移动较短线段的指针会得到一条相对较长的线段，这可以克服由宽度减小而引起的面积减小

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxvalue = 0;
        int left = 0;
        int right = height.size() - 1;
        while(left<right){
            maxvalue = max(maxvalue, min(height[left], height[right]) * (right - left));

            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }

        return maxvalue;
    }
};
```