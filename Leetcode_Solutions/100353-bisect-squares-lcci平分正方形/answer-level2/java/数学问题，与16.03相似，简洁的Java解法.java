```
class Solution {
    public double[] cutSquares(int[] square1, int[] square2) {
        // center1 (square1[0]+square1[2]/2.0, square1[1]+square1[2]/2.0)   计算两正方形中心位置
        double centerX1 = square1[0]+square1[2]/2.0;
        double centerY1 = square1[1]+square1[2]/2.0;
        double centerX2 = square2[0]+square2[2]/2.0;
        double centerY2 = square2[1]+square2[2]/2.0;
        if(centerX1==centerX2){     //中心连接线与y轴平行，包含无穷多解情况（中心重合），取斜率最大的
            double y1 = Math.min(square1[1], square2[1]);   //最底位置
            double y2 = Math.max(square1[1]+square1[2], square2[1]+square2[2]);     //最上位置
            return new double[]{centerX1, y1, centerX1, y2};
        }
        double k = (centerY2-centerY1)/(centerX2-centerX1);
        double b = centerY1-k*centerX1;
        double p1X, p1Y, p2X, p2Y;  //交点坐标
        if(Math.abs(k)<=1){     //斜率k小于1，交点在左右两侧
            // point1:(square1[0],k*square1[0]+b)  point2:(square1[0]+square1[2],k*(square1[0]+square1[2])+b)
            // point3:(square2[0],k*square2[0]+b)  point4:(square2[0]+square2[2],k*(square2[0]+square2[2])+b)
            p1X = square1[0]<square2[0]?square1[0]:square2[0];
            p1Y = k*p1X+b;
            p2X = square1[0]+square1[2]>square2[0]+square2[2]?(square1[0]+square1[2]):(square2[0]+square2[2]);
            p2Y = k*p2X+b;
        }else{      //交点在上下两侧
            // point5:((square1[1]+square1[2]-b)/k, square1[1]+square1[2])   point6:((square1[1]-b)/k, square1[1])
            // point7:((square2[1]+square2[2]-b)/k, square2[1]+square2[2])   point8:((square2[1]-b)/k, square2[1])
            // 交点是以上四点中x取值最小、最大的点
            p1X = Math.min(Math.min((square1[1]+square1[2]-b)/k,(square1[1]-b)/k), Math.min((square2[1]+square2[2]-b)/k,(square2[1]-b)/k));
            p1Y = k*p1X+b;
            p2X = Math.max(Math.max((square1[1]+square1[2]-b)/k,(square1[1]-b)/k), Math.max((square2[1]+square2[2]-b)/k,(square2[1]-b)/k));
            p2Y = k*p2X+b;
        }
        return new double[]{p1X, p1Y, p2X, p2Y};
    }
}
```
