### 思路
本题类似842题(将数组拆分成斐波那契序列)
1. 利用回溯思想，使用临时数组存储解析的数组，判断是否符合累加
2. 如果符合累加特性，则进行后续数字判断
3. 本题难点在于对整型溢出的边界的判断，这里使用最大的整型unsigned long long来存储临时数字

### 代码
```c++
class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num.size() < 3) {
            return false;
        }
        vector<unsigned long long> tmp, res;
        int len = 0;
        dfs(num, 0, num.size() - 1, len, tmp, res);
        return !res.empty();
    }
    void dfs(string& s, int start, int end, int& len, vector<unsigned long long>& tmp, vector<unsigned long long>& res) {
        if (!res.empty()) {
            return;
        }

        if (start > end) {
            if (len == s.size() && tmp.size() >= 3) {
                res = tmp;
            }
            return;
        }

        unsigned long long num = 0, sum = 0;
        size_t sz = tmp.size();
        string str;
        for (int i = start; i <= end; ++i) {
            if (num >= ULLONG_MAX/10) {
                return;
            }
            if (num == ULLONG_MAX/10 && ULLONG_MAX%10 < s[i] - '0') {
                return;
            }
            str.push_back(s[i]);
            if (i - start >= 1 && str[0] == '0') {
                return;
            }
            sum = 0;
            if (sz >= 2) {
                unsigned long long rest = ULLONG_MAX - tmp[sz - 1];
                if (tmp[sz - 2] > rest) {
                    return;
                }
                sum = tmp[sz - 1] + tmp[sz - 2];
            }
            num = stoull(str);
            if (sz < 2 || (sz >= 2 && sum == num)) {
                len += str.size();
                tmp.push_back(num);
                dfs(s, i + 1, end, len, tmp, res);
                tmp.pop_back();
                len -= str.size();
            }
        }
    }
};
```