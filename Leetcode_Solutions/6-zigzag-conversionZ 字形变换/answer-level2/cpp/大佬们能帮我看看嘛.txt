### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
    int n=s.size();
    int step=2*numRows-2;
    if(n<=numRows||step<2) return s;
    string result;
    vector<string> tmp(numRows);
    while (!s.empty()) {
        if(s.size()<=step){
            tmp.push_back(s);
            s.clear();
        }
        else{
            tmp.push_back(s.substr(0,step));
            s.erase(0,step);
        }
    }
    for(auto s:tmp){
        string str=s.substr(0,1);
        result+=str;
    }
    for(int i=1;i<numRows-1;++i){
        for(auto s:tmp){
//            auto size=s.size();
            if(i<s.size()){
                result+=s.substr(i,1);
            }
            if(step-i<s.size()){
                result+=s.substr(step-i,1);
            }
        }
    }
    for(auto s:tmp){
        if(s.size()>=numRows){
            result+=s.substr(numRows-1,1);
        }
    }
    return result;
    }
};
```