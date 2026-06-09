### 解题思路
按两种思路规则弥补即可

### 代码

```cpp
class Solution {
public:
    string maskPII(string S) {
        if ((S.front() >= 'a' && S.front() <= 'z') || S.front() >= 'A' && S.front() <= 'Z') {
            // email
            string::iterator  index = find(S.begin(), S.end(), '@');
            S.erase(S.begin() + 1, index - 1);
            S.insert(1, "*****");
            int sp = index - S.begin();
            for (int i = 0 ; i < S.size(); i++) {
                S[i] = tolower(S[i]);
            }

        } else {
            // phoneNumber
            string  str = "";
            for (int i = 0; i < S.size(); i++) {
                if ((S[i] >= '0' && S[i] <= '9')) {
                    str = str + S[i];
                }
            }
            int count = 0;
            int index = 0;
            string newStr = "";
            for (int i = str.size() - 1; i >= 0; i--) {
                count++;
                newStr = newStr + str[i];
                if (count == 4 || count == 7) {
                    newStr = newStr + '-';
                }
                if (count == 10 && str.size() > 10) {
                    newStr = newStr + '-';
                }
                if (count == 10) {
                    index = i;
                    break;
                }
            }
            reverse(newStr.begin(), newStr.end());
            string result = str.substr(0, index);
            S = result + newStr;
            int count1 = 0;
            for (int i = S.size() - 1; i >= 0; i--) {
                if (S[i] >= '0' && S[i] <= '9') {
                    count1++;
                    if (count1 > 4) {
                        S[i] = '*';
                    }
                }
            }
            if (str.size() > 10) {
                S.insert(S.begin(),'+');
            }
        }
        return S;
    }
};
```