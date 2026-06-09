### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> sc;
        stack<pair<char,int>> sp;
        for(auto a:s){
            if(sp.empty()){
                sp.push({a,1});
                sc.push(a);
            }
            else{
                if(a==sp.top().first){
                    ++sp.top().second;
                    sc.push(a);
                }
                else{
                    if(sp.top().second>=k){
                        int left=sp.top().second%k;
                        for(int i=0;i<sp.top().second-left;++i){
                            sc.pop();
                        }
                        if(left!=0)
                            sp.top().second=left;
                        else
                            sp.pop();
                    }
                    if(sp.empty()||sp.top().first!=a){
                        sp.push({a,1});
                        sc.push(a);
                    }
                    else{
                        sc.push(a);
                        ++sp.top().second;
                    }
                }
            }
        }
        if((!sp.empty())&&sp.top().second>=k){
            int left=sp.top().second%k;
            for(int i=0;i<sp.top().second-left;++i){
                sc.pop();
            }
        }
        string ans="";
        while(!sc.empty()){
            ans=sc.top()+ans;
            sc.pop();
        }
        return ans;

    }
};
```