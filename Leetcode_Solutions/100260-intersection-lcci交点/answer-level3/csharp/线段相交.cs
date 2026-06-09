### 解题思路
1:线段包围盒相交
2:线段端点在另外一个线段上
3:线段 只有唯一交点
向量叉乘
逆矩阵

线段顶点按照 x y 排序
线段参数方程 p = smallX + rate * delta

### 代码

```csharp
using VT = System.ValueTuple<double, double>;


class Line{
    public int[] start, end;
    private int dx, dy;
    public int minX, maxX, minY, maxY;
    public int[] smallX, bigX;
    public void Init(){
        //rate 0~ 1
        minX = Math.Min(start[0], end[0]);
        maxX = Math.Max(start[0], end[0]);
        minY = Math.Min(start[1], end[1]);
        maxY = Math.Max(start[1], end[1]);

        dx = maxX - minX;
        if(dx > 0){
            if(start[0] < end[0]){
                smallX = start;
                bigX = end;
            }else {
                smallX = end;
                bigX = start;
            }
        }else {//x 相等找Y
            if(start[1] < end[1]){
                smallX = start;
                bigX = end;
            }else {
                smallX = end;
                bigX = start;
            }
        }
        dx = bigX[0] - smallX[0];
        dy = bigX[1] - smallX[1];
        // dy = maxY - minY;

    }
    public VT GetPoint(double rate){
        var px = smallX[0] + rate * dx;
        var py = smallX[1] + rate * dy;
        return (px, py);
    }
    public double GetRate(int[] p){
        var dtX = p[0] - smallX[0];
        var dtY = p[1] - smallX[1];
        if(dx != 0){
            return dtX*1.0 / dx;
        }
        return dtY * 1.0 / dy;
    }
    public static bool NotInter(Line l1, Line l2){
        return l1.maxX < l2.minX || l1.minX > l2.maxX || l1.maxY < l2.minY || l1.minY > l2.maxY;
    }
    public static int[] Sub(int[] a, int[]b){
        var r = new int[2];
        r[0] = a[0] - b[0];
        r[1] = a[1] - b[1];
        return r;
    }
    public static int Cross(int[] a, int[] b){
        return a[0] * b[1] - a[1] * b[0];
    }
    public static double[] ToD(int[] v){
        return new double[] { v[0], v[1] };
    }
    //rate 0 最小点
    public static double[] Inter(Line l1, Line l2)
    {
        var orgDir = new int[] { l1.dx, l1.dy };
        var subDir = Sub(l2.smallX, l1.smallX);
        var subD2 = Sub(l2.bigX, l1.smallX);
        var c1 = Cross(orgDir, subDir);
        var c2 = Cross(orgDir, subD2);
        if (c1 == 0)
        {
            var rV = l1.GetRate(l2.smallX);
            if (rV >= 0 && rV <= 1)
            {
                return ToD(l2.smallX);
            }
        }
        if (c2 == 0)
        {
            var rV = l1.GetRate(l2.bigX);
            if (rV >= 0 && rV <= 1)
            {
                return ToD(l2.bigX);
            }
        }
        if (c1 * c2 > 0) return new double[] { };

        var od2 = new int[] { l2.dx, l2.dy };
        var sd1 = Sub(l1.smallX, l2.smallX);
        var sd2 = Sub(l1.bigX, l2.smallX);
        var cc1 = Cross(od2, sd1);
        var cc2 = Cross(od2, sd2);
        if (cc1 == 0)
        {
            var rV = l2.GetRate(l1.smallX);
            if (rV >= 0 && rV <= 1)
            {
                return ToD(l1.smallX);
            }
        }
        if (cc2 == 0)
        {
            var rV = l2.GetRate(l1.bigX);
            if (rV >= 0 && rV <= 1)
            {
                return ToD(l1.bigX);
            }
        }
        if (cc1 * cc2 > 0) return new double[] { };

        if(((c1*c2) == 0) || ((cc1 *cc2) == 0)){
            return new double[] { };
        }
        //完美交叉
        //p = l1.smallX + rate1 * delta
        //p = l2.smallX + rate2 * delta
        // dy/dx * smallX + c = smallY
        //c = smallY-dy/dx*smallX
        //dy *x + smallY*dx - dy*smallX = y*dx
        //l1.smallX-l2.smallX +rate1 * l1.delta- rate2*l2.delta = 0,0;
        //r1 = (r2 * l2d - sv)/l1d
        //(ld1x, -l2x ) r1 = l2-l1
        //(ld1y, -l2y)  r2 
        var sv = Sub(l2.smallX, l1.smallX);
        var dt = l1.dx * -l2.dy+l2.dx * l1.dy;//>0
        var negMat = (-l2.dy, l2.dx, -l1.dy, l1.dx);
        //netMat * (l2-l1) = r1, r2
        double r1 = negMat.Item1 * sv[0] + negMat.Item2 * sv[1];
        r1 /= dt * 1.0;
        var px = l1.smallX[0] + r1 * l1.dx;
        var py = l1.smallX[1] + r1 * l1.dy;
        return new double[] { px, py };
    }   
}
class LineInter{
    public double[] Intersection(int[] start1, int[] end1, int[] start2, int[] end2) {
        var l1 = new Line()
        {
            start = start1,
            end = end1,
        };
        var l2 = new Line()
        {
            start = start2,
            end = end2,
        };
        l1.Init();
        l2.Init();
        // Console.WriteLine(ObjectDumper.Dump(l1)+":"+ObjectDumper.Dump(l2));
        if(Line.NotInter(l1, l2)){
            return new double[] { };
        }
        return Line.Inter(l1, l2);
    }
    // static void Main(string[] arg)
    // {
    //     var j = File.ReadAllLines("testLine.json");
    //     var s1 = JsonSerializer.Deserialize<int[]>(j[0]);
    //     var e1 = JsonSerializer.Deserialize<int[]>(j[1]);
    //     var s2 = JsonSerializer.Deserialize<int[]>(j[2]);
    //     var e2 = JsonSerializer.Deserialize<int[]>(j[3]);

    //     var li = new LineInter();
    //     var r= li.Intersection(s1, e1, s2, e2);
    //     Console.WriteLine(JsonSerializer.Serialize(r));
    // }
}
public class Solution {
    public double[] Intersection(int[] start1, int[] end1, int[] start2, int[] end2) {
        var li = new LineInter();
        return li.Intersection(start1, end1, start2, end2);
    }
}
```