若能找到分离轴，则凸多边形不存在碰撞
```
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //投影到x轴无交集
        if((rec1[0]<=rec2[0]&&rec1[2]<=rec2[0])||(rec1[0]>=rec2[2]&&rec1[0]>=rec2[0]))
        {
            return false;
        }
        //投影到y轴无交集
        if((rec1[1]<=rec2[1]&&rec1[3]<=rec2[1])||(rec1[1]>=rec2[3]&&rec1[1]>=rec2[1]))
        {
            return false;
        }
        return true;
    }
```
