### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string toGoatLatin(string S) {
        int count = 1;
        vector<string> str;
        string res;
        string t ;
        for(int i=0; i<S.length(); i++){
            
            if(S[i]==' '){
                str.push_back(t) ;
                t = "";
            }else{
                t+=S[i] ;
            }
            
        }
        str.push_back(t);
        string k = "a";
        for(auto b:str){
            if(b[0]=='a'||b[0]=='e'||b[0]=='i'||b[0]=='o'||b[0]=='u'||b[0]=='A'||b[0]=='E'||b[0]=='I'||b[0]=='O'||b[0]=='U'){
                res+=b;
                res+="ma";
            }else{
                char k = b[0];
                b.erase(b.begin()+0);
                res+=b;
                res+=k;
                res+="ma";
            }
            res+=k;
            k+="a";
            res+=" ";
        }
        res.erase(res.begin()+(res.size()-1))  ;
        return res;
    }
};
```