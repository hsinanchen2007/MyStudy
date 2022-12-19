### 解题思路
按照"/"切分字符串后会发现问题简化了太多，重新组合切分后的结果即可。

### 代码

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v {};
        vector<string> res;
        string resstring = "/";
        split(path,v,"/");
        for(auto s:v){
            if(s=="."||s==""){
                continue;
            }
            else if (s==".."){
                if(!res.empty()) res.pop_back();
            }
            else{
                res.push_back(s);
            }
        }
        for(int i=0; i<res.size();i++){
            if(i==res.size()-1){
                resstring += res[i];
            }
            else{
                resstring += res[i] + "/";
            }
        }
        return resstring;
    }
    void split(const string& s,vector<string>& v,const string& c){
        string::size_type pos1,pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while(string::npos != pos2){
            v.push_back(s.substr(pos1,pos2-pos1));
            pos1 = pos2 + c.size();
            pos2 = s.find(c,pos1);
        }
        if(pos1 != s.length()){
            v.push_back(s.substr(pos1));
        }
    }
};
```