### 解题思路
循环套循环，遍历每一种情况，高取较小的，宽为j-i
使用max更新res的值
最后返回res

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int res = 0;
        for(int i = 0;i<size;i++){
            for(int j = i+1;j<size;j++){
                int high = min(height[i],height[j]);
                int width = j-i;
                int area = high*width;
                res = max(res,area);


            }
        }
        return res;
    }
};
```