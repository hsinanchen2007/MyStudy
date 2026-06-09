```
class Solution {
public:
    int compute(vector<int> a, vector<int> b){
        int x1=a[0],y1=a[1], x2=b[0],y2=b[1];
        int x=abs(x1-x2), y=abs(y1-y2);
        return x>y?x:y;
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res=0;
        for(int i=0;i<points.size()-1;i++){
            res+=compute(points[i],points[i+1]);
        }
        return res;
    }
};
```
