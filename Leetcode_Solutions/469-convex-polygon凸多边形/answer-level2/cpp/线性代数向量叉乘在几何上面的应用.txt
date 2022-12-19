复习：线性代数向量叉乘
（行列式法计算）
[https://blog.csdn.net/sunbobosun56801/article/details/78980467](向量叉乘)
思路：依次计算三个点构成的两个向量的叉乘，法向量方向不发生改变则是凸多边形  （右手定则判断法向量方向是否一致朝纸内或者一致朝纸外）
```
class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int currentDirection = 0, previousDirection = 0;  // 防止乘法范围越界, 若以相乘法判断方向，则用long long
        int len = points.size();
        int i = 0 , dx1, dy1, dx2, dy2;
        // 环边界，取模运算
        while(i < len){ 
            dx1 = points[(i+1) % len][0] - points[i][0];
            dy1 = points[(i+1) % len][1] - points[i][1];
            dx2 = points[(i+2) % len][0] - points[i][0];
            dy2 = points[(i+2) % len][1] - points[i][1];
            currentDirection = dx1 * dy2 - dx2 * dy1;
            // 共线三点也算凸多边形
            if(currentDirection != 0){
                if((currentDirection > 0 && previousDirection < 0) || (currentDirection < 0 && previousDirection > 0))
                    return false;
                else previousDirection = currentDirection;
            }
            i++;
        }
        return true;
    }
};
```

