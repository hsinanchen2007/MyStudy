### 解题思路
本题回溯方式类似131分隔回文串
1. 从字符串S中取出从1~不超过INT_MAX长度的数，存入临时数组
2. 当临时数组长度超过2时，比对当前数是否为前两个数之后；若相等，则放入临时数组，继续后续迭代
3. 本题边界在于整型溢出问题，需做适当判断

### 代码

```cpp
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        if (S.empty()) {
            return vector<int>();
        }
        vector<int> res, tmp;
        int len = 0;
        backtrace(S, 0, S.size() - 1, len, tmp, res);
        return res;
    }

    void backtrace(string& s, int start, int end, int& len, vector<int>& tmp, vector<int>& res) {
        if (start > end) {
            if (len == s.size() && tmp.size() >= 3) {
                res = tmp;
            }
            return;
        }

        string str;
        size_t sz = tmp.size();
        int num = 0;
        for (int i = start; i <= end; ++i) {
            if(num > INT_MAX/10) {
                return;
            }
            if (num == INT_MAX/10 && (INT_MAX % 10 <= s[i] - '0')) {
                return;
            }

            str.push_back(s[i]);
            if (str.size() >= 2 && str[0] == '0') {
                return;
            }
            num = stoi(str);
            long long sum = 0;
            if (sz >= 2) sum = (long)tmp[sz - 1] + (long)tmp[sz - 2];
            if (sum >= INT_MAX) return;
            if (sz < 2 || (sz >= 2 && sum == num)) {
                len += str.size();
                tmp.push_back(num);
                backtrace(s, i+1, end, len, tmp, res);
                tmp.pop_back();
                len -= str.size();
            }
        }
    }
};
```