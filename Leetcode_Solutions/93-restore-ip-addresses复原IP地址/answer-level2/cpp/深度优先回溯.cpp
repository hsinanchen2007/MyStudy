### 解题思路
和取出多个回文串类似

### 代码

```cpp
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.length()>12 || s.length()<4)
            return res;
        string res_s;
        dfs(0,s,res_s,0,res);
        return res;
    }

    void dfs(int b,const string &str, string &res_str,int cnt, vector<string>& res){
        if(cnt==4){
            if(b==str.length()){
                res_str.pop_back();
                res.push_back(res_str);
                return;
            }else{
                res_str.pop_back();
                while(res_str.back()!='.')
                    res_str.pop_back();

                return;
            }
        }

        int i;
        for(i=1;i<=3;i++){
            if(b+i>str.length())
                continue;

            string tmp=str.substr(b,i);
            if(!is_val(tmp,i)){
                continue;
            }
            
            string tmp_s = res_str + tmp;
            tmp_s.push_back('.');
            dfs(b+i,str,tmp_s,cnt+1,res);
        }
        return;
    }

    bool is_val(string& str, int i){
        if(i==1)
            return true;
        else if(i==2){
            return str[0]!='0';
        }
        else {
            if(str[0]=='0')
                return false;
            if(str[0]=='0' && str[1]=='0')
                return false;

            return atoi(str.c_str())<=255;
        }
        return true;
    }
};
```