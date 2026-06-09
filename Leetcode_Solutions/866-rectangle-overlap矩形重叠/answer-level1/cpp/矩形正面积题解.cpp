### 解题思路
1、计算矩形1到矩形2，x轴的距离
2、计算矩形1和矩形2，x轴的边长之和
3、进行比较。。

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        long int edge1 = abs(rec1[2] - rec1[0]);
        long int edge2 = abs(rec2[2] - rec2[0]);
        long int len = edge1 + edge2;
        long int len2 = -1;
        if(rec1[2] >= rec2[2]){
            len2 = abs(rec1[2] - rec2[0]);
        }else{
           len2 = abs(rec2[2] - rec1[0]);
        }
        
        if(len2 >= len){
            return false;
        }

        if(rec1[3] <= rec2[1] || rec1[1] >= rec2[3]){
            return false;
        }

        return true;
    }
};
```