**方法1参考官方题解**
### 投影法
```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) {
                                        //对于x来说，两个矩阵在x上的投影线段，如果存在重合部分则矩阵重叠，y同理
        return  min(r1[2],r2[2]) > max(r1[0],r2[0]) &&     
                min(r1[3],r2[3]) > max(r1[1],r2[1]);
    }
};
```

### 分类讨论
```cpp  
class Solution {
public:
    bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) {
                                        //依次考虑矩阵1位于2的左下右上4个方向的情况
        return !(r1[2]<=r2[0] ||  r1[3]<=r2[1] || r1[0]>=r2[2] || r1[1]>=r2[3]);   
    }
};
```
