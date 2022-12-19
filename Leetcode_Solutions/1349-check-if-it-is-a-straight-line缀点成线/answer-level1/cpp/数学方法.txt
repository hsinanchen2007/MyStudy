### 解题思路
此题完全可由数学方法解答。通过前两点可确定直线方程a*x+b*y+c=0，再将其他点带入验证即可。

### 代码

```cpp
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates)
    {
        if(coordinates.size()<=2) return true;
        int a=coordinates[0][1]-coordinates[1][1],b=coordinates[1][0]-coordinates[0][0],c=coordinates[0][0]*coordinates[1][1]-coordinates[1][0]*coordinates[0][1];
        for(int i=2;i<coordinates.size();i++)
            if(a*coordinates[i][0]+b*coordinates[i][1]+c!=0) return false;
        return true;
    }
};
```