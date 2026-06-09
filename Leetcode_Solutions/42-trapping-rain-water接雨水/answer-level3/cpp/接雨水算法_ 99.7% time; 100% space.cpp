### 解题思路
循环 位置 i = [ 0 ：size()-1 ]:
对于一个给定位置 i 分为两种情况：
    1.  i 后面无高于 i 的位置：寻找后续位置最高点max_pos,计算此区间积水量。
    2.  i 后面有高于 i 的位置：寻找第一个高于 i 的位置，也记为max_pos，计算此区间积水量。
之后将i更新到max_pos
    

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        size_t size_h = height.size();
        if(size_h < 3) return 0;
        size_t i=0; 
        while(i+1 < size_h && height[i] <= height[i+1]){
            i++;
        }
        if(i == size_h-1) return 0;
        //now i point to first high
        size_t max_pos;
        int sum = 0;
        while(i+1 < size_h){
            max_pos = i+1;
            int max = height[i+1];
            size_t j = i+1;
            while(j<size_h){
                if(height[j]>=height[i]){
                    max = height[j];
                    max_pos = j;
                    break;
                }
                if(height[j] >= max){
                    max = height[j];
                    max_pos = j;
                }
                j++;
            }
            int level = min(height[i], max);
            for(size_t k = i+1; k < max_pos; k++){
                sum+=(level-height[k]);
            }
            i = max_pos;
        }
        return sum;
    }
};
```