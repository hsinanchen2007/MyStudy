### 解题思路一

回溯算法，：

1. 0要单独处理；
2. 1位数字，从'1' ~ '9'开始dfs；
2. cur > high时剪枝；
3. 不能用字符串拼接，否则内存超出限制；
4. cur用长整型防止溢出。

执行用时 :32 ms

### 代码一

```cpp
class Solution {
private:
    vector<int> res;
public:
    vector<int> countSteppingNumbers(int low, int high) {
        if(low == 0)
            res.push_back(0);
        backtrack(-1, low, high);
        sort(res.begin(), res.end());
        return res;
    }
    
    void backtrack(long cur, int low, int high) {
        // int n = cur.size();
        // if(n == 0) {
        if(cur == -1) {
            for(int i=1; i<=9; i++) {
                // char d = '0' + i;
                // backtrack(cur + d, low, high);
                backtrack(i, low, high);
            }
            return;
        }
        // int num = atoi(cur.c_str());
        // if(num >= low && num <= high) {
        //      res.push_back(num);
        if(cur >= low && cur <= high) {
            res.push_back(cur);
        } else if(cur > high) {
            return;
        }
        // int last = cur[n-1] - '0';
        int last = cur % 10;
        // if(n == 1 && last == '0')
        //      return;

        /*
        char inc, dec;
        inc = '0' + last + 1;
        dec = '0' + last - 1;
        if(inc <= '9')
            backtrack(cur + inc, low, high);
        if(dec >= '0')
            backtrack(cur + dec, low, high);
        */
        if(last < 9)
            backtrack(cur * 10 + last + 1, low, high);
        if(last > 0)
            backtrack(cur * 10 + last - 1, low, high);
    }
};
```