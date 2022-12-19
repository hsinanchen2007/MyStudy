### 解题思路
注意点：
1、“0xxx”
2、字符串长度

### 代码

```cpp
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int len = num.size();
        vector<long> v = {-1, -1, -1, 0};
        stack<vector<long>> s;
        s.push(v);
        while (s.empty() == false) {
            vector<long> curr = s.top();
            s.pop();
            int next = curr[1] + 1;
            int bitNum = curr[1] - curr[0] + 1;
            string strTmp;
            for (int i = next; i < len; i++) {
                strTmp += num[i];
                if (strTmp[0] == '0' && strTmp.size() > 1) {
                    break;
                }
                if (curr[0] < 0 && (i - next) > (len - bitNum) / 2) {
                    break;
                }
                if (curr[0] == 0) {
                    if ((i - next) > (len - bitNum) / 2) {
                        break;
                    }
                }
                if (curr[0] > 0) {
                    long sum2 = curr[2] + curr[3];
                    string tmp = to_string(sum2);
                    if (strTmp != tmp) {
                        continue;
                    }
                }
                long val = stol(strTmp);
                if (curr[0] > 0 && val < curr[2] + curr[3]) {
                    continue;
                }
                if (curr[0] > 0 && val > curr[2] + curr[3]) {
                    break;
                }
                if (curr[0] > 0 && i == len - 1) {
                    return true;
                }
                s.push({next, i, curr[3], val});
            }
        }
        return false;
    }
};
```