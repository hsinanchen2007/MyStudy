按照.来分割，如果转换成int，对于超过32甚至64位的整数无法比较，那么直接比较字符串。
如果v1和v2长度相等，直接比较大小；如果不相等，直接返回比较结果。注意去除前导0
```
class Solution {
    string split(string &s){
        int i=0, j=0;
        for(; i<s.length() && s[i]=='0'; ++i);
        for(j=i; j<s.length() && s[j]!='.'; ++j);
        string t=s.substr(i,j-i);
        s=s.substr(j==s.length()?j:j+1);
        return t.length()?t:"0";
    }
public:
    int compareVersion(string version1, string version2) {
        int diff=0;
        for(; !diff && (version1.length() || version2.length());){
            string v1=split(version1), v2=split(version2);
            if(v1.length()==v2.length()) diff=v1.compare(v2);
            else return v1.length()>v2.length()?1:-1;
        }
        return diff>0?1:(diff<0?-1:0);
    }
};
```
