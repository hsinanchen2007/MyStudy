```
class Solution {
public:
    double r,x,y;
    Solution(double radius, double x_center, double y_center) {
        srand((unsigned) time(NULL));
        r=radius;
        x=x_center;
        y=y_center;
    }
    
    vector<double> randPoint() {
        double rx,ry;
        do
        {
            rx = 2 * (double)rand() / RAND_MAX - 1.;
            ry = 2 * (double)rand() / RAND_MAX - 1.;
        }
        while(rx*rx+ry*ry>1);
        return {x + rx * r, y + ry * r};
    }
};
```
