```
class Solution {
public:
    int romanToInt(string s) {
        int rc = 0;
        char last = '0';
        for (char c : s) {
            switch (c) {
                case 'M':     rc += (last == 'C') ? 800 : 1000;   break;
                case 'D':     rc += (last == 'C') ? 300 : 500;    break;
                case 'C':     rc += (last == 'X') ? 80 : 100;    break;
                case 'L':     rc += (last == 'X') ? 30 : 50;   break;
                case 'X':     rc += (last == 'I') ? 8 : 10;   break;
                case 'V':     rc += (last == 'I') ? 3 : 5;   break;
                case 'I':     rc += 1;   break;
                default:
                    break;
            }
            last = c;
        }
        return rc;
    }
};
```



