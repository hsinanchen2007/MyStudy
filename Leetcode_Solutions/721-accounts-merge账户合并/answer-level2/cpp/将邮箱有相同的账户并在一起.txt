- 将有相同邮箱的的账户并在一起，再把根节点的所有邮箱找出来即可
- 使用邮箱的索引而不能用用户名，因为可以重名
- 如果该邮箱是第一次出现则说明属于该用户 记录该邮箱所属的用户，否则将这个用户合并到该账户的拥有者下
- 找到每个用户所属的用户 把邮箱添加到所属的那个账户下

```cpp
class Solution {
public:
    vector<int>f;
    unordered_map<string,bool>hash;
    unordered_map<string,int>father;
    int find(int x){
        return x==f[x]?x:find(f[x]);
    }
    void merge(int x,int y){
        int xf = find(x),yf = find(y);
        if(xf!=yf){
            f[yf]=xf;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<vector<string>>res;
        f = vector<int>(n);
        for(int i=0;i<n;++i)f[i]=i;
        for(int i=0;i<n;++i){
            int len = accounts[i].size();
            for(int j=1;j<len;++j){
                if(!hash[accounts[i][j]]){      //如果该邮箱是第一次出现则说明属于该用户 记录该邮箱所属的用户
                    hash[accounts[i][j]]=1;
                    father[accounts[i][j]]=i;
                }else {
                    merge(father[accounts[i][j]],i);    //否则将这个用户合并到该账户的拥有者下
                }
            }
        }
        unordered_map<int,set<string>>accmail;
        for(int i=0;i<n;++i){
            int t = find(i),len = accounts[i].size();      //找到每个用户所属的用户 把邮箱添加到所属的哪个用户
            for(int j=1;j<len;++j){
                accmail[t].insert(accounts[i][j]);
            }
        }
        for(auto c:accmail){
            vector<string>ans;
            ans.push_back(accounts[c.first][0]);    //返回答案
            for(auto mail:c.second){
                ans.push_back(mail);
            }
            res.push_back(ans);
        }
        return res;
    }
};
```