

### 代码

```cpp
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        map<string,int> res;
        vector<string> final_res;
        if(s.size()==0){return final_res;}
        for(int i=0;i<=s.size()-10;i++){
            if(i+10>s.size()){break;}
            string tmp(s,i,10);
            res[tmp]++;
            if(res[tmp]>=2&&find(final_res.begin(),final_res.end(),tmp)==final_res.end()){
                final_res.push_back(tmp);
            }
        }
      
        return final_res;

    }
};
```