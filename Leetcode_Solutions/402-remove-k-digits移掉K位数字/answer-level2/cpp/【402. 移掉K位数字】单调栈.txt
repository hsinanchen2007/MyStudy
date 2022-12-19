## 思路：单调栈
维护一个递增栈，但当前元素小于栈顶元素，则移掉栈顶元素。
### 代码
```c++
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        int n = num.size(), m = n - k;        
        for (char c : num) {
            while (k && res.size() && res.back() > c) {
                res.pop_back();
                --k;
            }
            res.push_back(c);
        }
        res.resize(m);
        //去除前导0， 如10200，k = 1
        while (!res.empty() && res[0] == '0') {
            res.erase(res.begin());
        }
        return res.empty() ? "0" : res;
    }
};
```
