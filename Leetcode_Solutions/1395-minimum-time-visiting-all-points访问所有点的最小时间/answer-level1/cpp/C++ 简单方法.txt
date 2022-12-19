```
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int result=0;
        for(int i=0;i<points.size()-1;++i){
            int x=abs(points[i+1][0]-points[i][0]);
            int y=abs(points[i+1][1]-points[i][1]);
            result+=min(x,y)+abs(x-y);
        }
        return result;
    }
};
```
