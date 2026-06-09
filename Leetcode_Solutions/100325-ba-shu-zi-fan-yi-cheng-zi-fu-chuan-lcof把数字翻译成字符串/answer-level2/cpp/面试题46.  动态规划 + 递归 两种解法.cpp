```cpp


//1. 动态规划
class Solution {
private:
    bool check(const string & s, int i) {
        if (i + 1 == s.size())
            return false;
        int n = (s[i] - '0') * 10 + s[i+1] - '0';
        if (n >= 10 && n <= 25)
            return true;
        return false;
    }

public:
    int translateNum(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> memo(n + 1, 0);   // memo[i]表示从 索引i到结束 的子串可以翻译成的数量
        memo[n - 1] = 1;
        memo[n] = 1;
        for (int i = n - 2; i >= 0; i--) 
            memo[i] = memo[i+1] + check(s, i) * memo[i+2];
        return memo[0];
    }
};



////2. 递归
// class Solution {

// private:
//     int check(const string & s, int i) {
//         if (i + 1 == s.size())
//             return 0;
//         int n = (s[i] - '0') * 10 + s[i+1] - '0';
//         if (n >= 10 && n <= 25)
//             return 1;
//         return 0;
//     }

//     int helper(const string & s, int index) {
//         if (index == s.size() || index == s.size()-1)
//             return 1;
//         return helper(s, index + 1) + 
//             check(s, index) * helper(s, index + 2);
//     }

// public:
//     int translateNum(int num) {
//         string s = to_string(num);
//         return helper(s, 0);
//     }
// };
```