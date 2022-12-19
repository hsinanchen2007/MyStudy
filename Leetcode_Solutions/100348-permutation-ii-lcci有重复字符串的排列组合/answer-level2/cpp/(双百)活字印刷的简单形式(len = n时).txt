
- 具体可以看我的这篇题解[活字印刷题解](https://leetcode-cn.com/problems/letter-tile-possibilities/solution/hui-su-liang-chong-zuo-fa-hu-lue-ma-feng-by-wf_csu/)
![image.png](https://pic.leetcode-cn.com/13bbe0fbd7a810c39ad1e2de84076c16c76c9ff60bdad2ccb47f17dbea4ec290-image.png)

```cpp
class Solution {
public:
    int n,vis;
    vector<string>res;
    vector<string> permutation(string s) {
        n = s.size();
        if(!n)return res;
        string temp="";
        dfs(s,temp,vis,n);
        return res;
    }
    void dfs(string &s,string &current, int &vis, int remain){
        if(remain==0){
            res.push_back(current);
            return ;
        }
        for(int i=0;i<n;i++){
            if(vis & 1<<i)continue;
            if(check(s,vis,i))continue;
            vis|=1<<i;
            current+=s[i];
            dfs(s,current,vis,remain-1);
            vis -= 1<<i;
            current.pop_back();
        }
    }
    bool check(string &s,int  &vis,int &end){
            for(int i=0;i<end;i++){
                if(s[i]==s[end] && !(vis & (1<<i)))return true;
            }
            return false;
    }
};

```