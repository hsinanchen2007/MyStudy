### 解题思路
直接遍历

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        int n=S.length();
        if (n==0) return S;
        int temp=1;
        string res;
        res += S[0];
        for (int i=1;i<n;i++){
            if (S[i]!=S[i-1]) {
                res += to_string(temp)+S[i];
                temp=0;
            }
            temp++;
        }
        res += to_string(temp);
        return res.length()>=n ? S : res;

    }
};
```