- 用h&v记录水平和垂直方向的位移，向上h++，向下h--，向右v++，向左v--；
- 移动结束后，h&v若都为0，说明返回原点
```cpp
class Solution {
public:
    bool judgeCircle(string moves) {
        int h = 0, v = 0; //v: vertical h: horizontal
        for(auto i : moves){
            if(i == 'U')    ++ v;
            else if(i == 'D')   -- v;
            else if(i == 'R')   ++ h;
            else    -- h;
        }
        return h == 0 && v == 0? true : false; //当垂直和水平位移为0时，说明机器人返回原点
    }
};
```
