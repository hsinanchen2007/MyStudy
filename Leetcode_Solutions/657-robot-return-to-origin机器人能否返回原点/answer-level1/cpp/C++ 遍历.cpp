```c++
class Solution {
public:
    bool judgeCircle(string moves) {
        int h = 0, v = 0;
        for (char m : moves) {
            switch (m) {
                case 'L':
                    h--;
                    break;
                case 'R':
                    h++;
                    break;
                case 'U':
                    v++;
                    break;
                case 'D':
                    v--;
                    break;
            }
        }
        return !h && !v;
    }
};
```