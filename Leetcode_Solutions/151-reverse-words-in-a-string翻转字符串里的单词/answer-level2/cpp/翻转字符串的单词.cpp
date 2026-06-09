我佛了，有没有大神帮我看一下注释那里为什么不能用substr

```cpp
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        
        int start,end;
        string res="";
        string temp="";
        for(int i = 0;i < s.size();i++){
            if(s[i] != ' '){
                start = i;
                
                end = i;
                while(s[end] != ' ' && end < s.size())
                    end++;
                reverse(s.begin()+start,s.begin()+end);
                
                for(int j = start;j < end;j++){
                    res.push_back(s[j]);
                }
                //res += s.substr(start,end);
                res +=" ";
                i = end;
            }
        }
        if(!res.empty())
            res.pop_back();
        return res;
    }
};
```
