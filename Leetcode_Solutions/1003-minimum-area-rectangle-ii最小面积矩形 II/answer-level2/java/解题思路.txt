### 解题思路

此题难度不大，确定4点能够组成矩形，再计算组成的矩形中的最小面积即可。固转化判断4点能不能组成矩形。
我的思路是，从数组中取3点，判断能不能组成直角三角形，并找到直角的顶点。已知矩形的3个顶点，第4点也就顶了
假设a,b,c是已知的3个顶点且角abc是直角，那点d(dx,dy) dx = ax + cx - bx,dy = ay +cy -by.

### 代码

```java
class Solution {
    public double minAreaFreeRect(int[][] points) {
        if(points == null || points.length < 4 || points[0].length != 2)
            return 0;
        int n = points.length;
        double res = Double.MAX_VALUE;
        for(int i = 0; i < n - 3; i++){
            for(int j = i+1; j < n-2;j++){
                for(int k = j+1; k < n-1;k++){
                    if(isRightAngle(points[j],points[i],points[k])){
                        res = Math.min(res,minAreaFreeRect(points,j,i,k,k+1));
                        continue;
                    }
                    if(isRightAngle(points[i],points[j],points[k])){
                        res = Math.min(res,minAreaFreeRect(points,i,j,k,k+1));
                        continue;
                    }
                    if(isRightAngle(points[i],points[k],points[j])){
                        res = Math.min(res,minAreaFreeRect(points,i,k,j,k+1));
                        continue;
                    }
                }
            }
        }
        return res == Double.MAX_VALUE ? 0 : res;
    }
    private double minAreaFreeRect(int[][] points,int a,int b,int c,int start){
        int n = points.length;
        double res = Double.MAX_VALUE;
        int x = points[a][0] + points[c][0] - points[b][0];
        int y = points[a][1] + points[c][1] - points[b][1];
        for(int i = start; i < n;i++){
            if(points[i][0] == x && points[i][1] == y){
                double ab = Math.sqrt((points[a][0] - points[b][0]) * (points[a][0] - points[b][0])
                        + (points[a][1] - points[b][1]) * (points[a][1] - points[b][1]));
                double bc = Math.sqrt((points[c][0] - points[b][0]) * (points[c][0] - points[b][0])
                        + (points[c][1] - points[b][1]) * (points[c][1] - points[b][1]));
                return ab * bc;
            }
        }
        return res;
    }
    private boolean isRightAngle(int[] a,int[] b, int[] c){
        return (a[0] - b[0]) * (b[0] - c[0]) + (a[1] - b[1]) * (b[1] - c[1]) == 0;
    }
}
```