读了大佬的解法 [传送门](https://leetcode-cn.com/problems/valid-number/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-1-4/)，对责任链在这道题目的应用感到眼前一亮，用来解这种分类较为复杂的题目确实写起来很有条理，读起来也赏心悦目。

```
struct Validator{
    virtual bool validate(const string&)=0;
};

class integarValidator:public Validator
{
public:
    bool validate(const string& s)
    {
        int i=s.find_first_not_of(' ');
        if(s[i]=='+' || s[i]=='-') ++i;
        int d=0;
        for(; i<s.length() && ::isdigit(s[i]); ++d,++i);
        for(; i<s.length() && s[i]==' '; ++i);
        return i==s.length() && d>0 ;
    }
};
//regex r("\\s*[+-]?(\\d+\\.?\\d*|\\.\\d+)?\\s*$");
class floatValidator:public Validator
{
public:
    bool validate(const string& s)
    {
        int i=s.find_first_not_of(' ');
        if(s[i]=='+' || s[i]=='-') ++i;
        int d1=0,point=0,d2=0;
        for(; i<s.length() && ::isdigit(s[i]); ++d1,++i);
        for(; i<s.length() && s[i]=='.'; ++point,++i);
        if(point!=0 && point!=1) return false;
        for(; i<s.length() && ::isdigit(s[i]); ++d2,++i);
        for(; i<s.length() && s[i]==' '; ++i);
        return i==s.length() && (point&&(d1||d2)||d1) ;
    }
};
//regex r("\\s*[+-]?(\\d+\\.?\\d*|\\.\\d+)(e[+-]?\\d+)?\\s*$");
class scienceValidator:public Validator
{
public:
    bool validate(const string& s)
    {
        int i=s.find_first_of('e');
        floatValidator before;
        integarValidator after;
        string before_e =s.substr(0,i);
        string after_e = s.substr(i+1,s.size()-i);
        if(before_e.size()-1==before_e.find_last_of(' ') )
            return false;
        if(after_e.find_first_of(' ')==0)
            return false;

        return before.validate(before_e) && after.validate(after_e);
    }
};

class NumberValidator
{
    string s ;
    vector<Validator*> val;
public:
    NumberValidator(const string& input):s(input)
    {
        val.push_back(new integarValidator());
        val.push_back(new floatValidator());
        val.push_back(new scienceValidator());
    }
    ~NumberValidator()
    {
        for(auto i=0;i<val.size();i++)
            delete val[i];
    }
    operator bool()
    {
        for(auto i=0;i<val.size();i++)
            if(val[i]->validate(s))
                return true;
        return false;
    }
};


class Solution {
public:
    bool isNumber(string &s) {
        return NumberValidator(s);
    }
}; 
```
