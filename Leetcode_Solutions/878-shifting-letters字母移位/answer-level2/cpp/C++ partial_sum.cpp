```
inline int plusMod26(const int& x, const int& y) {
    return (x+y)%26; // 必须取余，否则导致结果溢出。
}
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        if (S.size() > shifts.size()) { return ""; }
        if (S.empty() || shifts.empty()) { return S; }
        // 预计算得到最终移位次数。O(n)时间
        partial_sum(shifts.rbegin(), shifts.rend(), shifts.rbegin(), plusMod26);
        // 对S[i]移位shifts[i]次。O(n)时间
        for (size_t i=0; i<S.size(); ++i) {
            S[i] = 'a'+(S[i]-'a'+shifts[i])%26;
        }
        return S;
    }
};
```
