因为这题就是求最小步骤数的，所以只要求出s,t两个字符串之间相同的字符有多少，然后用总字符串的长度减去相同的字符数量就能得到最小步骤数，可以通过构造两个map来实现相同字符数的统计，然后从a到z统计一下拥有相同字符的数量的min值就可以实现了，下附代码
```
class Solution {
public:
    int minSteps(string s, string t) {
        int n=0;
        map<char,int> a,b;
        for (int i=0;i<s.length();i++) {
            map<char,int>::iterator iter;
            iter = a.find(s[i]);  
            if(iter != a.end()) a[s[i]]++;else a[s[i]]=1;
        }
        for (int i=0;i<t.length();i++) {
            map<char,int>::iterator iter;
            iter = b.find(t[i]);  
            if(iter != b.end()) b[t[i]]++;else b[t[i]]=1;
        }
        for (char j='a';j<='z';j++){
            map<char,int>::iterator iter1;
            map<char,int>::iterator iter2;
            iter1 = a.find(j);  iter2 = b.find(j); 
            if(iter1 != a.end()&& iter2!=b.end()) n=n+min(a[j],b[j]);
        }
        return s.length()-n;
    }
};
```
