1. 执行一次指令，根据执行完毕后机器人的位置和方向判断。
2. 当执行完成后机器人位置不变，仍在原点，机器人会困在环中。
3. 或者机器人位置改变了，而方向也改变了，因为机器人每次移动的距离相等，偏转的角度相同，机器人会走过一个正多边形路径后回到原点。
4. 只有沿着开始方向直线行走，机器人才能离开。
5. 使用复数运算，计算机器人的位置和方向。
6. 初始位置pos{0, 0}, 方向{0, 1}。
```
class Solution {
public:
    bool isRobotBounded(const string& instructions) {
        complex<int> pos{0, 0};
        complex<int> step{0, 1};
        const complex<int> left{0, 1};
        const complex<int> right{0, -1};
        for (const char ch : instructions)
            if ('G' == ch) pos += step;
            else if ('L' == ch) step *= left;
            else if ('R' == ch) step *= right;
        return (pos == complex<int>{0, 0}) || (step != complex<int>{0, 1});
    }
};
```
