## 思路
- 既然可以走对角线，当走对角线时，我们既向x平移了一步，又向y平移了一步
- 简言之，我们只需要知道当前点到达下一个点时，沿x移动的步数多，还是沿y移动的步数多。
- 只需要走其中步数较多的方向，而步数较少的方向，可以在向走步数较多的方向时通过走对角线顺便走完。

```cpp
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int m = points.size(), minpath = 0;
        for(int i = 1; i < m; ++ i){
            int disx = abs(points[i][0] - points[i-1][0]);
            int disy = abs(points[i][1] - points[i-1][1]);
            if(disx < disy) minpath += disy; //看看哪个长就走哪个
            else    minpath += disx;
        }
        return minpath;
    }
};
```
