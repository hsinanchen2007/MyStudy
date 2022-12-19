### 解题思路
自己做的无论时时间还是空间的开销都挺大的，于是看了题解。
自己最开始的想法是采用两层循环逐个比较，虽然也有剪枝（要求如果后面的比前面记录的最大的还小，那么就减掉）。但是依然不够，看了题解采用双指针的方式。显然要快很多。

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftIndex = 0;
        int rightIdex = height.size() - 1;
        int result = 0;
        int leftMax = 0;
        int rightMax = 0;
        bool turnFlag = height[leftIndex] < height[rightIdex];
        while (leftIndex < rightIdex) {
            if (turnFlag) {
                if (height[leftIndex] > leftMax) {
                    leftMax = height[leftIndex];
                    if (result < height[leftIndex] * (rightIdex - leftIndex))
                        result  = height[leftIndex] * (rightIdex - leftIndex);
                    
                }
                leftIndex++;
            }
            else {
                if (height[rightIdex] > rightMax) {
                    rightMax = height[rightIdex];
                    if (result < height[rightIdex] * (rightIdex - leftIndex))
                        result = height[rightIdex] * (rightIdex - leftIndex);
                     
                }
                rightIdex--;
            }
            turnFlag = height[leftIndex] < height[rightIdex]; 
        }
        return result;
    }
};
```