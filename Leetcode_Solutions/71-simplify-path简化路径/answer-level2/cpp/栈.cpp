### 解题思路
..出栈，.忽略，其他进栈

### 代码

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> res;
        path.erase(0,path.find_first_not_of('/'));

        while(path.size()!=0){
            
            string tmp="";
            
            string::size_type pos = path.find_first_of('/');
            if(pos==string::npos){
                pos = path.size();
            }

            tmp = path.substr(0,pos);
            path.erase(0,pos);        
            if(tmp==".."){
                if(res.size()>0)
                    res.pop_back();
            }else if(tmp== "."){
                if(path.find_first_not_of('/')!=string::npos){
                    path.erase(0,path.find_first_not_of('/'));
                }else{
                    path = "";
                }
                continue;
            }else{
                res.push_back(tmp);
            }  

            if(path.find_first_not_of('/')!=string::npos){
                path.erase(0,path.find_first_not_of('/'));
            }else{
                path = "";
            }
        } 

        string s = "";
        for(int i=0;i<res.size();i++){
            s+="/";
            s+=res[i];
        }
        return s.size()==0?"/":s;
    }

};
```