分别计算时针和分针的角度

分针的角度简单：直接走过的分钟数 * 每分钟的角度(6度)
时针的角度：记得对12取模，防止多算一圈，整数部分的角度乘好后，按照分钟来计算比例角度，加和

然后用时针角度 - 分针角度，对180取模
```
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double dpd = 0.1, md = minutes * 60 * dpd, hd;
        hd = (hour % 12) * 30 + double(minutes) * 0.5;
        
        double res = md - hd;
        res = res >= 0 ? res : -res;
        return res > 180 ? 360 - res : res;
    }
};
```