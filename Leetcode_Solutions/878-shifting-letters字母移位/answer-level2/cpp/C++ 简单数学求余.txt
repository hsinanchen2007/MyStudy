```
class Solution {
public:
    static int op (int x, int y) {
        return (x + y) % 26;
    }
    string shiftingLetters(string S, vector<int>& shifts) {
        vector<int> shift_sum(shifts);
        partial_sum(shifts.rbegin(), shifts.rend(), shift_sum.rbegin(), op);
        for (int i = 0; i < shift_sum.size(); ++i) {
            S[i] = ((S[i] - 'a' + shift_sum[i]) % 26) + 'a';
        }
        return S;
    }
};
```
![image.png](https://pic.leetcode-cn.com/779e504d97cf3c0f7b1e0e4d5f2789b7bf1eafb156a2efb59908d87cf2867451-image.png)

