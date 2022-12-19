### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        string ans = "";
        char pre;
        int cnt;
        for (int i=0; i < S.size(); i++) {
            if (i==0) {
                pre = S[i];
                cnt = 1;
            }  else {
                if (S[i]==pre) {
                    cnt++;
                } else if (S[i]!=pre) {
                    ans += pre + to_string(cnt);
                    pre = S[i];
                    cnt = 1;
                }
            }
        }
        ans += pre + to_string(cnt);
        ans = ans.size()<S.size()? ans: S;
        return ans;

    }
};
```