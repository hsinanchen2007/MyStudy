![捕获55555.PNG](https://pic.leetcode-cn.com/ca0c01a5570d5a12888c12f29c3e68c4e0f2b49422f8f534b17a4569c6a3a99e-%E6%8D%95%E8%8E%B755555.PNG)

class Solution {
public:
    void dfs(string& s, int N, int K) {
        if (s.size() == N) {
            res.push_back(stoi(s));
            return;
        }
        char c = s.back();
        for (char i = '0'; i <= '9'; i++) {
            if (abs(i - c) == K) {
                s.push_back(i);
                dfs(s, N, K);
                s.pop_back();
            }
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        res.clear();
        string s;
        if (N == 1) {
            return {0,1,2,3,4,5,6,7,8,9};
        }
        for (char i = '1'; i <= '9'; i++) {
            s.push_back(i);
            dfs(s, N, K);
            s.pop_back();
        }
        return res;
    }
    vector<int> res;
};
