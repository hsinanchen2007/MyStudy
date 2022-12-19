### 解题思路
如果这样写，第31个测试用例过不了，提示超出内存限制

```
res = res + c + to_string(count);
```
必须写成这样才能过：

```
res += c + to_string(count);
```
### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        if(S.empty()) {
            return "";
        }
        string res = "";
        char c = S[0];
        int count = 1;
        for(int i = 1; i < S.size(); i++) {
            if(S[i] == c) {
                count++;
            }
            else {
                res += c + to_string(count);
                c = S[i];
                count = 1;
            }
        }
        res += c + to_string(count);
        return res.size() < S.size() ? res : S;


    }
};
```