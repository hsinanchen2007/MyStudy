思路1：
如果两个点不在同一条直线上就尽量先走对角线
flag1,flag2代表x,y向那个方向移动右正左负，上正下负
```c++
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size(),res=0;
        int x=points[0][0],y=points[0][1];
        for(int i=1;i<n;i++){
            if(x!=points[i][0]&&y!=points[i][1]){//走斜线
                int flag1=1,flag2=1;//默认斜右上
                if(x>points[i][0]&&y<points[i][1]){//斜左上
                    flag1=-1;
                }else if(x<points[i][0]&&y>points[i][1]){//斜右下
                    flag2=-1;
                }else if(x>points[i][0]&&y>points[i][1]){//斜左下
                    flag1=-1,flag2=-1;
                }
                while(x!=points[i][0]&&y!=points[i][1]){
                    res++;
                    x+=flag1;
                    y+=flag2;
                }
            }
            if(y==points[i][1]&&x==points[i][0]){
                continue;
            }else if(y==points[i][1]){//走水平线
                res+=abs(points[i][0]-x);
            }else {//走竖直线
                res+=abs(points[i][1]-y);
            }
            x = points[i][0], y = points[i][1];
        }
        return res;
    }
};
```
思路2：
分析可以发现最小距离就是两个点的横坐标和纵坐标的最大差值的和
```c++
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int x = points[0][0], y = points[0][1];
        int ans = 0;
        for (int i = 1; i < points.size(); ++i) {
            ans += max(abs(x - points[i][0]), abs(y - points[i][1]));
            x = points[i][0];
            y = points[i][1];
        }
        return ans;
    }
};
```
