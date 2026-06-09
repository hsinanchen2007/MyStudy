### 解题思路
%10 /10分解数字后，分别处理4、9、[0,3],[5,8]

### 代码

```cpp
static char roman10[] = {'I', 'X', 'C', 'M'};
static char roman5[] = {'V', 'L', 'D'}; 
class Solution {
public:
    string intToRoman(int num) {
        int a[4];
        int cnt = 0;
        while (num) {
            a[cnt] = num % 10;
            num /= 10;
            cnt++;
        }
        string ret;
        for (int i = cnt - 1; i >= 0; --i) {
            if (a[i] == 4) {
                ret += roman10[i];
                ret += roman5[i];
            }
            else if (a[i] == 9) {
                ret += roman10[i];
                ret += roman10[i+1];
            }
            else if (a[i] < 4) {
                // [0, 3]
                for (int j = 0; j < a[i]; ++j)  ret += roman10[i];
            }
            else {
                // [5, 8]
                ret += roman5[i];
                for (int j = 5; j < a[i]; ++j) ret += roman10[i];
            }
        }
        return ret;
    }
};
```