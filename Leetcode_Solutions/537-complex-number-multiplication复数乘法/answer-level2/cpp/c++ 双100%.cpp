```
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ai,aj,bi,bj;
        parse(a,ai,aj);
        parse(b,bi,bj);
        int i=ai*bi-aj*bj;
        int j=ai*bj+bi*aj;
        return to_string(i)+"+"+to_string(j)+"i";
    }
    void parse(string &s, int &i,int &j){
        int start=0;
        while(start<s.size()&&s[start]!='+')++start;
        i=std::stoi(s);
        j=std::stoi(s.substr(start+1));
    }
};
```
