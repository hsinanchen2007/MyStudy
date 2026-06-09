### 计数实现

```c
class Solution {
public:
    string compressString(string S) {
        string res = "";
        int cnt = 1;

        for (int i = 1;i <= S.size(); i ++ ) {
            if (S[i] == S[i - 1]) cnt ++ ;
            else {
                res += S[i - 1] + to_string(cnt);
                cnt = 1;
            }
        }
        return res.size() >= S.size() ? S : res;
    }
};
```

---

### 2. 双指针实现

```c
class Solution {
public:
    string compressString(string S) {
        string res = "";
        int i = 0, j = 0;
        int cnt = 0;
        
        while (j <= S.size()) {
            if (S[i] == S[j]) {j ++, cnt ++ ;}
            else {
                res += S[i] + to_string(cnt);
                i = j;
                cnt = 0;
            }
        }
        return res.size() < S.size() ? res : S;
    }
};
```