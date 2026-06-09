执行用时 :8 ms, 在所有 C++ 提交中击败了93.08%的用户
内存消耗 :8.9 MB, 在所有 C++ 提交中击败了91.36%的用户

这里有个细节就是，在定义三点坐标值的时候，有人可能会在最后一层循环里一次性列出来，但实际上在每层循环中分别定义当前点的坐标值会更效率。

```
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        
        double S_max = 0;
        
        //三重循环粗暴遍历
        for(int i=0; i+2<points.size(); i++){
            
            //定义三点的坐标值
            double x1 = points[i][0];
            double y1 = points[i][1];
            
            for(int j=i+1; j+1<points.size(); j++){
                
                double x2 = points[j][0];
                double y2 = points[j][1];
                
                for(int k=j+1; k<points.size(); k++){

                    double x3 = points[k][0];
                    double y3 = points[k][1];
                    
                    double s = (double)abs( x1*y2 + x2*y3 + x3*y1 - x1*y3 - x2*y1 - x3*y2 )/2;//平面坐标系三角形面积公式
                    
                    //cout << "x1 = " << x1 << " " << "y1 = " << y1 << endl;
                    //cout << "x2 = " << x2 << " " << "y2 = " << y2 << endl;
                    //cout << "x3 = " << x3 << " " << "y3 = " << y3 << endl;
                    //cout << "s = " << s << endl;
                    
                    if( s > S_max )
                        S_max = s;  
                }
            }
        }
        
        return S_max;
        
        
    }
};
```
