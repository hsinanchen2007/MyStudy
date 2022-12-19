### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isNumber(string s) {
        //去掉首位空格
        int start=s.find_first_not_of(' ');
        if (start==string::npos) return false;
        int end=s.find_last_not_of(' ');
        s=s.substr(start, end-start+1);
        if (s.empty()) return false;
        //按顺序判断
        int i=0;
        bool res=scanInt(s,i);
        //小数部分
        if (s[i]=='.'){
            i++;
            res=scanUnsignedInt(s, i) || res;
        }
        //指数部分
        if (s[i]=='e' || s[i]=='E'){
            i++;
            res=res && scanInt(s, i);
        }
        return res && i==s.size();
    }

    bool scanInt(const string s, int& i){
        if (s[i]=='+' || s[i]=='-') i++;
        return scanUnsignedInt(s, i);
    }

    bool scanUnsignedInt(const string s, int& i){
        int current=i;
        while(i<s.size() && s[i]>='0' && s[i]<='9')
            i++;
        return i>current;
    }
};
```