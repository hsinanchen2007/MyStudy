### 解题思路
用其中两个点确定一条直线a*x+b*y+c=0，验证第三个点是否在该直线上

### 代码

```cpp
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
    int a=points[0][1]-points[1][1],b=points[1][0]-points[0][0],c=points[0][0]*points[1][1]-points[1][0]*points[0][1];
    if(a*points[2][0]+b*points[2][1]+c==0) return false;
    return true;
    }
};
```