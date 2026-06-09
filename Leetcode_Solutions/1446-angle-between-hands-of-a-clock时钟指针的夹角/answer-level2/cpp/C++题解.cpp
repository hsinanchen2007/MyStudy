### [1344. 时钟指针的夹角](https://leetcode-cn.com/problems/angle-between-hands-of-a-clock/)

#### 题解

  + 统计分针和圆心到12点的连线的夹角
  + 统计时针和圆心到12点的连线的夹角，需要注意要加上相应比例的【非整数时】所带来的偏移角度
  + 两者角度可能成锐角和钝角，所以所得【时分角度差】应该和【与360度取差的结果】取最小值
  + 注意处理小数
  + 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)
#### 代码
```cpp
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double x = minutes*6;
        double y = hour * 30 + (minutes*1.0)/2;
        return min(360-fabs(y-x), fabs(y-x));
    }
};
```