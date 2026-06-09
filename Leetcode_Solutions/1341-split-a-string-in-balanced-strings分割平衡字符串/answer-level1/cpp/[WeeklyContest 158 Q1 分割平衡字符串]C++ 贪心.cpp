[[WeeklyContest 158 Q1 分割平衡字符串]C++](https://leetcode-cn.com/problems/split-a-string-in-balanced-strings/solution/weeklycontest-158-q1-fen-ge-ping-heng-zi-fu-chuan-/)
[[WeeklyContest 158 Q2 可以攻击国王的皇后]C++ 迭代](https://leetcode-cn.com/problems/queens-that-can-attack-the-king/solution/weeklycontest-158-q2-ke-yi-gong-ji-guo-wang-de-hua/)
[[WeeklyContest 158 Q3 掷骰子模拟]C++ 动态规划](https://leetcode-cn.com/problems/dice-roll-simulation/solution/weeklycontest-158-q3-zhi-tou-zi-mo-ni-c-dong-tai-g/)
[[WeeklyContest 158 Q4 最大相等频率]C++ 分类讨论](https://leetcode-cn.com/problems/maximum-equal-frequency/solution/weeklycontest-158-q4-zui-da-xiang-deng-pin-lu-c-fe/)  


思路：l,r分别记录到当前位置为止，字符"L"和"R"出现的次数，因此l==r时，必平衡。
```
class Solution {
public:
    int balancedStringSplit(string s) {
        int l = 0, r = 0, ans = 0;
        for(auto a : s){
            if(a=='L') l++;
            else r++;
            if(l == r) ans++;
        }
        return ans;
    }
};
```
