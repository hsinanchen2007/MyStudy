### 代码

```cpp
class Solution {
public:
    // 做的有点复杂了,可以参考之前解法
    // int lengthOfLastWord(string s) {
    //     int n = s.length();
    //     if (n == 0) return 0;
    //     bool pureSpace = true;
    //     int right = n;

    //     for (int i = n-1; i >= 0; --i)
    //     {
    //         if (pureSpace && s[i] != ' ')
    //         {
    //             pureSpace = false;
    //             right = i + 1;
    //         }
    //         if (!pureSpace && s[i] == ' ') return right - i -1;
    //     }

    //     return pureSpace ? 0 : right;
    // }

    int lengthOfLastWord(string s) {
        int n = s.length() - 1;
        while (n>=0)
        {
            if (s[n] != ' ') break;
            n--;
        }
        if (n < 0) return 0;

        int k = n;
        while (k>=0)
        {
            if (s[k] == ' ') break;
            k--;
        }

        if (k < 0) return n+1;
        else
            return n - k;
    }
};
```