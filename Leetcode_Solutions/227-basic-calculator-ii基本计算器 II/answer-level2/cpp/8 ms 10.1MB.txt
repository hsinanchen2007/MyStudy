表达式中值包含数字和操作符两种字符串，分别写出查找函数。
第一个肯定是数字，往后就是操作符和数字依次出现。
用res记录表达式的值，last记录最后一个操作数，下一个操作只与最后一个操作数有关。


```
class Solution {
public:
    int calculate(string s) {
        int i=0;
        vector<int> ans;
        auto p = findNum(s, i);
        i = p.first;
        int res = p.second, last=p.second;
        while(i<s.size()) {
            auto op = findOp(s, i);
            auto np = findNum(s, op.first);
            if(op.second=='+') last = np.second;
            else if(op.second=='-') last = -np.second;
            else if(op.second=='*') res -= last, last *=np.second;
            else if(op.second=='/') res -= last, last /=np.second;
            i = np.first;
            res += last;
        }
        return res;
    }
    
    pair<int, int> findNum(string& s, int i) {
        while(s[i]==' ') i++;
        int ans = 0;
        while(i<s.size() && s[i]>='0' && s[i]<='9') {
            ans = ans*10 + (s[i++]-'0');
        }
        while(i<s.size() && s[i]==' ') i++;
        return {i, ans};
    }
    pair<int, char> findOp(string& s, int i) {
        while(s[i]==' ') i++;
        return {i+1, s[i]};
    }
};
```