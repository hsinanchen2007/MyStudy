```
class Solution {
public:
    int solve(int n){
        int num=0;
        while(n!=0){
            num+=n%10;
            n=n/10;
        }
        return num;
    }
    int countLargestGroup(int n) {
        map<int,vector<int>>mp;
        for(int i=1;i<=n;i++){
            int num=solve(i);
            mp[num].push_back(i);
        }
        // auto v=--mp.end();
        // int res=v.second.size();
        vector<int>cnt(1e4+10,0);
        for(auto v:mp){
            cnt[v.second.size()]++;
        }
        int res=0;
        for(int i=0;i<cnt.size();i++){
            if(cnt[i]!=0)res=cnt[i];
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/4a2519ca94f94b392891c379a7b96f57820eb0a2878c37b82ea859d293aefbf4-image.png)
