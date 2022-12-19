### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        string res="";
        vector<string> split_str;
        split(s,split_str," ");

        for(int i=split_str.size()-1; i>=0; i--)
        {
            res+=split_str[i];
            res+=" ";
        }
        if(res.size()>0) res.pop_back();

        return res;
    }

    void split(const string& s, vector<string>& tokens, const string& delimiters=" ")
    {
        string::size_type lastPos=s.find_first_not_of(delimiters,0);
        string::size_type pos=s.find_first_of(delimiters,lastPos);
        while(lastPos!=string::npos || pos!=string::npos)
        {
            tokens.push_back(s.substr(lastPos,pos-lastPos));
            lastPos=s.find_first_not_of(delimiters,pos);
            pos=s.find_first_of(delimiters,lastPos);
        } 
    }

    // void split(const string& s, vector<string>& tokens, const string& delimiters=" ")
    // {
    //     string::size_type lastPos=s.find_first_not_of(delimiters,0);
    //     string::size_type pos=s.find_first_of(delimiters,lastPos);
    //     while(string::npos!=pos || string::npos!=lastPos){
    //         tokens.push_back(s.substr(lastPos,pos-lastPos));
    //         lastPos=s.find_first_not_of(delimiters,pos);
    //         pos=s.find_first_of(delimiters,lastPos);
    //     }
    // }
};
```