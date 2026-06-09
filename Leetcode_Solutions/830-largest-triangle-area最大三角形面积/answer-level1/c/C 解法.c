# 代码：
```
double computelength(int* p1, int* p2){
    return sqrt((p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]));
}


double largestTriangleArea(int** points, int pointsSize, int* pointsColSize){
    int i,j,k;
    double max = 0,result = 0,p;
    double a,b,c;


    for(i = 0; i < pointsSize - 2;i++){
        for( j  = i + 1; j < pointsSize - 1; j++){
            for(k = j + 1; k < pointsSize;k++){
                a = computelength(points[i], points[j]);
                b = computelength(points[j], points[k]);
                c = computelength(points[k], points[i]);

                p = (a+b+c) * 0.5;
                result = sqrt( p * (p - a) * (p - b) * (p - c)) ;
                if(result > max){
                    max = result;
                }

            }
        }
    }
    return max;
}
```
