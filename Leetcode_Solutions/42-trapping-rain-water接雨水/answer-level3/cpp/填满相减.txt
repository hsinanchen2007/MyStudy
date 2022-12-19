### 解题思路
与大家一样，先遍历找最大值所在位置同时计算总和，之后分别从左右两端向最大值位置遍历，将比当前最大值小的height[i]变成当前最大值，也就是相当于给凹陷灌上水，计算左右两边的总和。之后将所得的值与第一遍遍历得到的原始总和相减即可得到水的体积。（也算是解决立一道困难题。。。）

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2){
            return 0;
        }
        int MaxIdx = 0;
        int Sum = 0;
        int CurMax = 0;
        int CurSum = 0;
        for(int i = 0; i < height.size(); i++){//找到最大值所在位置，顺便计算数组的和
            //Max = max(Max, height[i]);
            if(height[i] > height[MaxIdx]){
                MaxIdx = i;
            }
            Sum += height[i]; 
        }
        for(int i = 0; i < MaxIdx; i++){//从最大值左边开始遍历并计算总和。将比当前最大值小的height[i]变成当前最大值，也就是相当于给凹陷处灌上水
            CurMax = max(CurMax, height[i]);
            if(height[i] < CurMax){
                height[i] = CurMax;
            }
            CurSum += height[i];
        }
        CurMax = 0;
        for(int i = height.size() - 1; i >= MaxIdx; i--){//从最大值右边开始遍历，计算总和
            CurMax = max(CurMax, height[i]);
            if(height[i] < CurMax){
                height[i] = CurMax;
            }
            CurSum += height[i];
        }
    return CurSum - Sum;//两者相减就是水的体积

    }
};
```