### 解题思路
字符串每个位置与后面的位置交换
回溯
set去重

### 代码

```cpp
class Solution {
public:
    set<string>se;
    vector<string> permutation(string s) {
        vector<string>res;
        if(!s.size())    return res;
        help(0,s);
        for(auto it : se){
            res.push_back(it);
        }
        return res;
    }
    void help(int pos,string& s){
        if(pos == s.size()){
            se.insert(s);
            return;
        }
        
        for(int i = pos;i < s.size();i++){
            if(pos != i)
                swap(s[i],s[pos]);
            help(pos+1,s);
            if(pos != i)
                swap(s[i],s[pos]);
        }
    }
};
```