执行用时 :4 ms, 在所有 C++ 提交中击败了90.32%的用户
内存消耗 :8.6 MB, 在所有 C++ 提交中击败了51.84%的用户
```c++
class Solution {
public:
    string addBinary(string a, string b) {
        auto m = max(a.size(), b.size());
        string r; r.reserve(m);
        int ia = a.size()-1, ib = b.size()-1;
        bool carry = false;
        while (ia>=0 || ib>=0) {
            char ta = ia>=0?a[ia]:'0';
            char tb = ib>=0?b[ib]:'0';
            char ch = (
                (ta!=tb&&!carry) ||
                (ta==tb&&carry)
               ) ? '1': '0';
            r.push_back(ch);
            carry = (ta!=tb&&carry) || (ta=='1'&&tb=='1');
            ia--, ib--;
        }
        r.resize(carry?m+1:m, '1');
        reverse(r.begin(), r.end());
        return r;
    }
};
```
ch真值表
ta+tb+carry=ch, c=newCarry
0+0+0=0, c=0
0+0+1=1, c=0
0+1+0=1, c=0,
0+1+1=0, c=1
1+0+0=1, c=0
1+0+1=0, c=1
1+1+0=0, c=1
1+1+1=1, c=1