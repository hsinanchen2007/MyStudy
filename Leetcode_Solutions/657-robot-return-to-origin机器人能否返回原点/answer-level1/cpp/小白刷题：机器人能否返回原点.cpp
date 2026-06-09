模拟过程，看最后能否回到原点

代码：
```
class Solution {
public:
    bool judgeCircle(string moves) {
        int pos[2] = {0};
        int len = moves.length();
        for(int i = 0; i < len; i++) {
            switch(moves[i]) {
                case 'R': pos[0]++; break;
                case 'L': pos[0]--; break;
                case 'U': pos[1]++; break;
                case 'D': pos[1]--; break;
                default: break;
            }
        }
        return pos[0] == 0 && pos[1] == 0;
    }
};
```
