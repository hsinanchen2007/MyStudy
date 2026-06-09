### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double a,b,c,d;
            a=coordinates[0][0];
            b=coordinates[0][1];
            c=coordinates[1][0];
            d=coordinates[1][1];
            for(auto i:coordinates){
                if((i[1]-b)*(c-a)!=(i[0]-a)*(d-b)) return false;
            }
            return true;
    }
};
```