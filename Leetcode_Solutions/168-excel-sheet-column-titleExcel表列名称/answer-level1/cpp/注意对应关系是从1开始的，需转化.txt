### 解题思路
注意对应关系中是从1开始的，因此我们预先对n做处理，然后进行%26和/26

### 代码

```cpp
class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while(n > 0){
            int mod = (n-1) % 26;
            res += ('A' + mod);
            n = (n-1) / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```