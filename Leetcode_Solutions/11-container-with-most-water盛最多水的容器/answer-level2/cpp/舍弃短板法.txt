### 解题思路
此处撰写解题思路
从两端开始，逐渐计算容量；取到最大值中
然后逐渐舍弃两端影响最大的短板，向中间靠拢。
如果相等，我们选择两端同时向中间靠拢，为什么呢？先看看移动其中一个会怎么样？
比如说移动左边向右一步，无论它比原来是大i点的长度是大是小，他容量都必定变小了，所以只移动一个只能舍近求远。
当两端相等时，同时向中间靠拢，逐渐可得最大，复杂度O(n)。
### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int maxV=INT_MIN;
        while(i<j)
        {
            if(height[i]>height[j])
            {
                maxV=max(height[j]*(j-i),maxV);
                j--;
            }
            else if(height[i]<height[j])
            {
                maxV=max(height[i]*(j-i),maxV);
                i++;
            }
            else{
                maxV=max(height[i]*(j-i),maxV);
                i++;
                j--;
            }
        }
        return maxV;
    }
};
```