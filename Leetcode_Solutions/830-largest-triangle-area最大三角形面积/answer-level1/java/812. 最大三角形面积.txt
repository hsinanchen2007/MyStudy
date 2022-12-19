/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/12
 *
 * 解题思路: 三角形坐标公式  S= ath.abs(x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3)/2.0
 *
 *   海伦公式 p = (a + b + c)/2   S=Math.sqrt(p*(p-a)*(p-b)*(p-c));
 *
 *   此题建议用坐标公式
 *
 */
```
public class leetcode812 {

    public double largestTriangleArea(int[][] points) {

        double a , b , c;
        double S = 0 , temp;
        for(int i = 0;i < points.length - 2;i++){
            for(int j = 0;j < points.length - 1;j++){
                for(int k = 0;k < points.length;k++){
                    a = Math.sqrt((points[i][0] - points[j][0])*((points[i][0] - points[j][0])) + (points[i][1] - points[j][1])*((points[i][1] - points[j][1])));
                    b = Math.sqrt((points[i][0] - points[k][0])*((points[i][0] - points[k][0])) + (points[i][1] - points[k][1])*((points[i][1] - points[k][1])));
                    c = Math.sqrt((points[j][0] - points[k][0])*((points[j][0] - points[k][0])) + (points[j][1] - points[k][1])*((points[j][1] - points[k][1])));
                    temp = getS(a,b,c);
                    if(S < temp){
                        S = temp;
                    }
                }
            }
        }
        return S;

    }

    //海伦公式
    public double getS(double a , double b , double c){
        double p = (a + b + c)/2;
        return Math.sqrt(p*(p-a)*(p-b)*(p-c));
    }

    public double largestTriangleArea2(int[][] points) {
        double S = 0;
        double x1 , x2 , x3, y1 , y2 , y3;
        for(int i = 0;i < points.length;i++){
            x1 = points[i][0];
            y1 = points[i][1];
            for(int j = i+1;j < points.length;j++){
                x2 = points[j][0];
                y2 = points[j][1];
                for(int k = j+1;k < points.length;k++){
                    x3 = points[k][0];
                    y3 = points[k][1];
                    //坐标公式
                    S = Math.max(S , Math.abs(x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3)/2.0);
                }
            }
        }
        return S;
    }

    public static void main(String[] args) {
        leetcode812 leetcode812 = new leetcode812();
        leetcode812.largestTriangleArea2(new int[][]{{0,0},{0,1},{1,0},{0,2},{2,0}});
    }
}
```