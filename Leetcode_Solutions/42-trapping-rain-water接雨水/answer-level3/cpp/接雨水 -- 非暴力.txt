### 解题思路
核心思路：接满水后的规律是，到达峰值之前是非连续递增，跟没接水的差值就是水的值；

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        // find max
        int max_val = 0; 
        for (int i = 0; i < height.size(); i++) {
            max_val = max(max_val, height[i]);
        }
        vector<int> water(height.size(), 0);
        int start = 0;
        int maxstart = 0;
        int end = height.size() - 1;
        int maxend = 0;
        while (start < end) {
            while (start < end && height[start] != max_val) {
                maxstart = max(height[start], maxstart);
                water[start] = maxstart;
                start++;
            }
            while (start < end && height[end] != max_val) {
                maxend = max(height[end], maxend);
                water[end] = maxend;
                end--;
            }
            // 到达峰值就退出，可能存在多个峰值
            if (height[start] == max_val && height[end] == max_val) {
                water[end] = max_val;
                water[start] = max_val;
                break;
            }
        }
        // 处理多个峰值的情况
        while (start < end) {
            water[start] = max_val;
            start++;
        }
        // 计算接满水和没接水的差值就是接的水，注意只有一个值的情况；
        int num = 0;
        for (int i = 0; i < height.size() && height.size() > 1; i++) {
            cout<< water[i] <<endl;
            num += water[i] - height[i];
        }
        return num;
    }
};
```