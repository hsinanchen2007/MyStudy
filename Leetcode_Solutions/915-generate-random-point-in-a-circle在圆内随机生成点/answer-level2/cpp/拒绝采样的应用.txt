方法介绍参考：https://blog.csdn.net/tywwwww/article/details/98397495


```
class Solution {//拒绝采样的应用
public:
    Solution(double radius, double x_center, double y_center) {
        r=radius;
        x0=x_center;
        y0=y_center;
    }
    
    vector<double> randPoint() {//找到参考分布，就是正方形均匀分布
        while(true){
            double x=(double)rand()/RAND_MAX*2*r-r;
            double y=(double)rand()/RAND_MAX*2*r-r;

            double dis=x*x+y*y;
            if(dis<=r*r)//判断是否满足
                return {x+x0,y+y0};
            
        }
        return {};
    }
private:
    double r;
    double x0;
    double y0;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
```
