直接使用三点面积公式即可
由于数据量为50，可以直接暴力求解。
```
class Solution {
public:
    //三个不在一条直线上的点构成一个三角形
    //由数据量可知，直接求就可以了
    double largestTriangleArea(vector<vector<int>>& points) {
        int n=points.size();
        double res=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int x1=points[i][0],y1=points[i][1];
                    int x2=points[j][0],y2=points[j][1];
                    int x3=points[k][0],y3=points[k][1];
                    res=max(res,abs((0.5)*(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2)));
                }
            }
        }
        return res;
    }
};
```
