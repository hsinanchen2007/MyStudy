### 解题思路
1.使用平方根找到接近的宽度值，不断尝试直到可以被面积整除即为需要的宽度。

### 代码

```cpp
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int W = sqrt(area);
        while(area % W != 0){
            W--;
        }
        return {area / W,W};
    }
};
```