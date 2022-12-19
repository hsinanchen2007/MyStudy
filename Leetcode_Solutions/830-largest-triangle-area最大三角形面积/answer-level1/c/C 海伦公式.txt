计算三角形面积的方法，可以转化成已知三角形三边a, b, c 使用海伦公式求解

虽然方法绕一点，但也顺便学习了一种求三角形面积的方法。


![Screenshot from 2019-06-15 08-34-06.png](https://pic.leetcode-cn.com/8e9e1504e47c132e3ca136d00efb321e37eeef50c675c44e202d601433c21365-Screenshot%20from%202019-06-15%2008-34-06.png)

```
inline double getLength(int *point1, int *point2)
{
    return sqrt((point1[0]-point2[0])*(point1[0]-point2[0]) + \
                (point1[1]-point2[1])*(point1[1]-point2[1]));
}

double largestTriangleArea(int** points, int pointsSize, int* pointsColSize){
    int  i, j, k;

    double a;
    double b;
    double c;
    double p;
    double s;
    double ret;
    
    
    for(i = 0; i < pointsSize - 2; i++) {
        for(j = i + 1; j < pointsSize - 1; j++) {
            for(k = j + 1; k < pointsSize; k++) {
                a = getLength(points[i],points[j]);
                b = getLength(points[i],points[k]);
                c = getLength(points[j],points[k]);
                
                p = (a + b + c) / 2;
                s = sqrt(p * (p - a) * (p - b) * (p - c));
                ret = ret < s ? s : ret;
            }
        }
    }
    
    return ret;
}
```