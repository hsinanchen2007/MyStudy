```
class Solution {
    public int maxPoints(int[][] points) {
        if(points.length<3)return points.length;
        int maxp = 2;
        for(int i=0;i<points.length-1;i++){
            for(int j=i+1;j<points.length;j++){
                int temp = 0;
                long x1 = points[i][0],y1 = points[i][1];
                long x2 = points[j][0],y2 = points[j][1];
                if(x1==x2&&y1==y2){//如果重复则(x2,y2)取和(x1,y1)不同的任意一点
                    x2++;
                    y2++;
                }
                for(int k=0;k<points.length;k++){//遍历所有点，统计在直线上的点
                    long x = points[k][0];
                    long y = points[k][1];
                    if(((y-y1)*(x2-x1)==(x-x1)*(y2-y1))){
                        temp++;
                    }
                }
                maxp = Math.max(maxp,temp);
            }
        }
        return maxp;
    }
}
```
