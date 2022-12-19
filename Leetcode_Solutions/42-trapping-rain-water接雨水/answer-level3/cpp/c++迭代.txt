### 解题思路
# c++
思路：将计算区间分成两段，以最后一个最大（有可能出现多个最大柱子）的柱子为边界计算两边的积水量
1.保存最后一个最大位置和最大位置的值
2.从左边开始搜索
3.从右边开始搜索
### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 2) return 0;
        //查找最后一个最大的柱子
        int maxPos;
        int max = 0; 
        for(int i=0;i < height.size();i++){
            if(height[i] > max){
                max = height[i];
                maxPos = i;
            }
        }
        //计算总的接水量
        int leftPos = 0;
        int rightPos = height.size() - 1;
        int sum = 0;
        int leftmax = 0;
        int rightmax = 0;
        //计算最后一个最大柱子前的可接雨水量
        for(;leftPos < maxPos - 1;leftPos++){
            if(height[leftPos] > leftmax){
                leftmax = height[leftPos];
            }
            if(leftmax > height[leftPos + 1]){
                sum += leftmax - height[leftPos + 1];
            } 
        }
        //计算最后一个最大柱子后的雨水量
        for(;rightPos > maxPos;rightPos--){
            if(height[rightPos] > rightmax){
                rightmax = height[rightPos];
            }
            if(rightmax > height[rightPos - 1]){
                sum += rightmax - height[rightPos - 1];
            }
        }

        return sum;
    }

};
```