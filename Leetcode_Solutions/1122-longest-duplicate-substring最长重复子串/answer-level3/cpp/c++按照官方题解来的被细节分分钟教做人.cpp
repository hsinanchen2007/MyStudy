### 解题思路
看着官方题解整的；最初的时候在查找字符串对应的key时，用的vector，直接循环遍历查找，结果死活超时...
后来换了stl的unordered_set，理论上应该是接近O(1)的查找，总算混过去了...
整个思路正确了，一些小细节也要注意,不然分分钟被教做人。
### 代码

```cpp
class Solution {
private:
    int maxSubLen;
    int beginId;

    bool check_dupstr(vector<int>& S, int strLen, int subLen) {
        unsigned int tmp = 0;
        unsigned int al = 1;
        unordered_set<unsigned int> str_code;

        for (int i = 0; i < subLen; i++) {
            al = al *26 % UINT_MAX;
            tmp = tmp *26 % UINT_MAX;
            tmp += S[i];
        }

        str_code.insert(tmp);

        for (int i = 1; i < (strLen - subLen + 1); i++) {
            tmp = tmp * 26 % UINT_MAX - S[i - 1] * al % UINT_MAX + S[i + subLen - 1];
            if (str_code.find(tmp) != str_code.end()) {
                //out = S.substr(i, subLen);
                if (subLen > maxSubLen) {
                    maxSubLen = subLen;
                    beginId = i;
                }
                return true;
            }
            str_code.insert(tmp);
        }

        return false;
    }
public:
    string longestDupSubstring(string S) {
        int strLen = S.size();
        int left = 1;
        int right = strLen;
        vector<int> strNum;
        string res = "";

        maxSubLen = 0;
        beginId = 0;

        for (int i = 0; i < strLen; i++) {
            strNum.push_back(S[i] - 'a');
        }

        while (left < right) {
            int subLen = (left + right) / 2;
            if (check_dupstr(strNum, strLen, subLen)) {
                left = subLen + 1;
            } else {
                right = subLen;
            }
        }
        if (maxSubLen != 0) {
            res = S.substr(beginId, maxSubLen);
        }
        return res;
    }
};
```