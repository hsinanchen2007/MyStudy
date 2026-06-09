# 代码里注释的很详细了
```
class Solution {
    public int mySqrt(int x) {
        //都用double，int和float会过不了大数值测试
        //极限上下界
        double offset = 0.05d;
        //跳跃点
        double point = x;
        //跳跃上界
        double r = x;
        //跳跃下界
        double l = 0;
        while (true) {
            //判断是否达到“极限”
            if (point * point + offset > x && point * point - offset < x)
                break;
            //大了，改变跳跃上界
            if (point * point > x) {
                r = point;
                point = (r + l) / 2;
            }
            //小了，改变跳跃下界
            else if (point * point < x) {
                l = point;
                point = (r + l) / 2;
            }
        }
        return (int) point;
    }
}
```