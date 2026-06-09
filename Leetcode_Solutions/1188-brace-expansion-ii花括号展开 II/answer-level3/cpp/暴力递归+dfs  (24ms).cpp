1. 难点在于层次遍历；
2. 需要用set来存储临时结果防止出现重复；

### 代码写的太烂，全都是暴力解决，大家凑合帮忙指正下-_-

```
class Solution {
public:
    bool insertArray(set<string> & dict,vector<string> & res){
        for(auto s : dict){ res.push_back(s);}
        return true;
    }
    
    bool insertDict(set<string> & res,vector<string> & strs){
        for(auto s: strs){ res.insert(s);}
        return true;
    }
    
    bool helper2(vector<vector<string>> & m,vector<string> & res,int l,string curr){
        if(l >= m.size()){
            if(curr.size() > 0){ res.push_back(curr);}
            return true;
        }
        for(int i = 0;i < m[l].size(); ++i){
            helper2(m,res,l+1,curr+m[l][i]);
        }
        return true;
    }
    
    vector<string> helper1(vector<vector<string>> & m){
        vector<string> res;
        string curr;
        helper2(m,res,0,curr);
        return res;
    }
    
    vector<string> braceExpansionII(string expression) {
        vector<vector<string>> merge;
        set<string> dict;
        vector<string> ans;
        vector<string> prev;
        string curr = "";
        int n = expression.size();
        int i = 0;
        
        if(n <= 0){
            return ans;
        }
        while(i < n){
            if(expression[i] == '{'){
                ++i;
                int count = 1;
                curr = "";
                while(i < n && count > 0){
                    if(expression[i] == '}'){ count--;}
                    if(expression[i] == '{'){ count++;}
                    if(count > 0){ curr.push_back(expression[i]);}
                    ++i;
                }
                merge.push_back(braceExpansionII(curr));
            }else if(expression[i] == ','){
                prev = braceExpansionII(expression.substr(i+1));
                insertDict(dict,prev);
                break;
            }else if(expression[i] >= 'a' && expression[i] <= 'z'){
                curr = "";
                while(i < n && expression[i] >= 'a' && expression[i] <= 'z'){
                    curr.push_back(expression[i++]);
                }
                merge.push_back(vector<string>(1,curr));
            }else{
                ++i;
            }
        }
        
        prev = helper1(merge);
        insertDict(dict,prev);
        insertArray(dict,ans);
        
        return ans;
    }
};
```
