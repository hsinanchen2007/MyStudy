```
class Solution {
public:
    /*
    * 三点P1(x1,y1),P2(x2,y2),P3(x3,y3)共线要满足任意两点连线的斜率相等，
    * 即公式：（y3-y2）/(x3-x2) = (y2 - y1) / (x2 - x1) = (y3 - y1) / (x3 - x1)
    * 因为含有分母可能为0的情况，所以把除法变为乘法（以第一个等号为例），并化简：
    * x1(y2-y3) + x2(y3-y1) + x3(y1-y2) = 0
    */
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        if(coordinates.size() <= 2) return true;
        
        for(int i = 2; i < coordinates.size(); i++)
        {
            int x1 = coordinates[i-2][0], y1 = coordinates[i-2][1];
            int x2 = coordinates[i-1][0], y2 = coordinates[i-1][1];
            int x3 = coordinates[i][0], y3 = coordinates[i][1];
            // 公式：x1(y2-y3) + x2(y3-y1) + x3(y1-y2) = 0
            if(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)!=0) return false;
        }
        
        return true;
    }
};
```