## 思路
这题可以理解为在1-N的范围内有多少个由集合内的`digit`组成的`number`，计数的话用数位dp套模板即可。
## 代码
```c++
class Solution {
public:
    vector<int> memo;
    vector<int> digit;
    vector<int> in;
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        in.resize(10);
        fill(in.begin(), in.end(), 0);
        for (auto s:D) {
            in[s[0]-'0'] = 1;
        }        
        return solve(N);
    }
    int solve(int N) {
        int len = 0;
        digit.resize(26);
        while (N) {
            digit[++len] = N%10;
            N /= 10;
        }
        memo.resize(len+1);
        fill(memo.begin(), memo.end(), -1);
        return dfs(len, true, true);
    }
    int dfs(int pos, int limit, int lead) {
        if (!pos) {return !lead;}
        if (!limit&&!lead && memo[pos] != -1) return memo[pos];
        int up = limit ? digit[pos] : 9;
        int ret = 0;
        for (int i=0; i<=up; ++i) {
            if (lead && i == 0) {
                ret += dfs(pos-1, limit&&i==up, lead && i==0);
            }else if(in[i]) {
                ret += dfs(pos-1, limit&&i==up, lead && i==0);
            }
        }
        if (!limit && !lead) {
            memo[pos] = ret;
        }
        return ret;
    }
};
```
## ps
主要逻辑就是`dfs()`函数了，注意使用`vector<int> in`记录每位的`digit`是否存在，然后排除掉只有一位数并且为0的情况。