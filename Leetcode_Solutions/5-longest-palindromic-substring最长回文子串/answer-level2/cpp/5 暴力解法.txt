![image.png](https://pic.leetcode-cn.com/ebc98ba9ba1dd968b9923e5a635718144f7895f55e82a30cf303756a7fe1c8db-image.png)

### 代码

```cpp
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        int len = s.length(),
            subLen = 0; //子串长度
        for (int i=0; i<len; i++) {
            //回文子串长度为奇数
            int j;
            for (j=1; j<=i; j++) 
                if (i+j < len) {
                    if (s[i-j] != s[i+j]) {
                        break;
                    }
                }
                else
                    break;
            
            j--;
            if (2*j+1 > subLen) {
                subLen = 2*j+1;
                res = s.substr(i-j, subLen);
            }

            //回文子串长度为偶数
            for (j=0; j<=i; j++) 
                if (i+j+1 < len) {
                    if (s[i-j] != s[i+j+1]) 
                        break;
                }
                else
                    break;
            
            j--;
            if (2*j+2 > subLen) {
                subLen = 2*j+2;
                res = s.substr(i-j, subLen);
            }
        }
        return res;
    }
};
```