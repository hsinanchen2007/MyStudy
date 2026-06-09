```
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'I')
                result += 1;
            else if (s[i] == 'V') {
                if (i > 0 && s[i - 1] == 'I')
                    result -= 2;
                result += 5;
            }
            else if (s[i] == 'X') {
                if (i > 0 && s[i - 1] == 'I')
                    result -= 2;
                result += 10;
            }
            else if (s[i] == 'L') {
                if (i > 0 && s[i - 1] == 'X')
                    result -= 20;
                result += 50;
            }
            else if (s[i] == 'C') {
                if (i > 0 && s[i - 1] == 'X')
                    result -= 20;
                result += 100;
            }
            else if (s[i] == 'D') {
                if (i > 0 && s[i - 1] == 'C')
                    result -= 200;
                result += 500;
            }
            else {
                if (i > 0 && s[i - 1] == 'C')
                    result -= 200;
                result +=1000;
            }
        }
        return result;
        
    }
};
```
