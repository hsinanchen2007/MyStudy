### 解题思路

执行用时 :8 ms, 在所有 cpp 提交中击败了93.04%的用户
内存消耗 :10.1 MB, 在所有 cpp 提交中击败了100.00%的用户

两点最短距离，肯定是先斜着走，再水平（竖直）走。走到同一水平（竖直）线，再走直线到达目标。

那么前进的总时间就是两点的x轴距离与y轴距离中较大的那一个，因为斜着走相当于x轴y轴都走了一格。

最后两两时间相加既是答案。

### 代码

```cpp
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        //先斜着走 直到先到达横坐标或纵坐标 再水平走
        int time = 0; // 总时间
        
        for(int i=0; i<points.size()-1 ; i++){
            int x_distance = 0, y_distance = 0; //两点x轴距离与y轴距离
            x_distance = abs(points[i][0] - points[i+1][0]);
            y_distance = abs(points[i][1] - points[i+1][1]);
            if(x_distance >= y_distance)
                time += x_distance;
            else
                time += y_distance;
        }

        return time;
    }
};
```