### 解题思路
回溯算法
### 代码

```cpp
class Solution {
public:
    vector<string>res;
    vector<string> permutation(string s) {
        string r_res="";
        sort(s.begin(), s.end());   //先排序，使相同的字符连在一起
        string flag(s.size(),'0');  //标志位字符串
        process(s,s.size(),r_res,flag);
        return res;
    }
    void process(string s,int n,string r_res,string flag){
        if(r_res.size()==s.size()){
            res.push_back(r_res);
            //return ;
        }
        else{
            for(int i=0;i<n;i++){
                if(flag[i]=='0'){
                    if(i>0 && s[i]==s[i-1] && flag[i-1]=='1') continue;
                    r_res.push_back(s[i]);
                    flag[i]='1';
                    process(s,n,r_res,flag);
                    r_res.pop_back();
                    flag[i]='0';
                }
            }
        }
    }
};
```