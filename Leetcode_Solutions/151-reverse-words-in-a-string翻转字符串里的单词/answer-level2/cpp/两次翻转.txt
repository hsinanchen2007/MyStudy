可以将单词翻转，然后再整体翻转。
```
class Solution {
public:
    string reverseWords(string s) {
        string res, t;
        for(stringstream istr(s); istr>>t; res.append(" "+t))
            reverse(t.begin(),t.end());
        reverse(res.begin(),res.end());
        if(res.length()) res.pop_back();
        return res;
    }
};
```
上面使用stringstream间接使用空间O(N)，而且字符串的添加（append）也很耗时。
下面就地翻转，首先去除多余空格，然后就地翻转。
```
class Solution {
public:
    string reverseWords(string s) {
        int len=0;
        for(int i=0; i<s.length();){
            i=s.find_first_not_of(' ',i);
            if(i==s.npos) break;
            for(; i<s.length() && s[i]!=' '; s[len++]=s[i++]);
            if(i<s.length()) s[len++]=s[i++];
        }
        s.erase(len);
        if(s.back()==' ') s.pop_back();
        for(int i=0, j; i<s.length();){
            j=s.find(' ',i);
            reverse(s.begin()+i,j!=s.npos?s.begin()+j:s.end());
            i=s.find_first_not_of(' ',j);
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
```

