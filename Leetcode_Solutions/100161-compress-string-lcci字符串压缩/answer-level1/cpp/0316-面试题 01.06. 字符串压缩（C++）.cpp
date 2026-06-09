### 解题思路
直接法-模拟

### 代码

```cpp
#include <string>
using namespace std;

class Solution {
public:
    string compressString(string S) {
        int length = S.length();
        string res = "";
        char curCh;
        int curCount = 0;
        for (int i = 0; i < length; i++) {
            if (i == 0) {
                curCh = S[i];
                curCount = 1;
            } else {
                //与curCh相同
                if (S[i] == curCh) {
                    curCount++;
                } else {
                    res += curCh;
                    res += to_string(curCount);
                    curCh = S[i];
                    curCount = 1;
                }
            }
        }
        res += curCh;
        res += to_string(curCount);

        if (res.length() >= length) {
            return S;
        } else {
            return res;
        }

    }
};

```