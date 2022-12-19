### 解题思路
简单的回溯算法模板

### 代码

```cpp
class Solution {
public:
    vector<string>res;
    vector<string> permutation(string S) {
        string s;
        int n=S.size();
        vector<int>flag(n);//标志位序列
        process(S,s,n,flag);
        return res;
    }
    void process(string S,string& s,int n,vector<int>&flag)
    {
        //终止条件
        if(s.size()==S.size()){
            res.push_back(s);          
        }
        else{
            for(int i=0;i<n;i++){
                if(flag[i]==0){
                    s+=S[i];
                    flag[i]=1;
                    process(S,s,n,flag);
                    s.pop_back();//回退上一步
                    flag[i]=0;
                }
            }
        }
    }
};
```