题干中出现描述：
每个 words[i] 和 result 都会被解码成一个**没有前导零**的数字。

事实上，**标程没有判断是否出现前导零**的情况。

**现提供测试数据如下：**

["AB","CD","EF"]
"GHIJ"

如不允许前导零出现（即 $G=0$ ）则无解，然而**期望结果为true**


![争议样例](https://pic.leetcode-cn.com/209a0c593511481d2c095e36ef378d99645be789c37c91e0161eb99f0bb9a738-image.png)


另附16ms通过代码，如若删除注释部分则可以保持不出现前导零的情况：
```C++
class Solution {
    bool ok;
    bool vis[10];
    int n;
    int num[26];
    vector<char> lead;
    
    void dfs(int p,int pp,int jin,vector<string>& words, string& result){
        if (ok) return;
        if (p==n){
            if (jin!=0) return;
            ok=true;/*
            for (auto &i:lead){
                if (num[i-'A']==0){
                    ok=false;
                    return;
                }
            }*/
            for (int i=0;i<26;++i){
                if (num[i]!=-1){
                    cout<<char('A'+i)<<"="<<num[i]<<' ';
                }
            }
            cout<<endl;
            return;
        }
        int rl=jin,rr;
        for (int i=pp;i<words.size();++i){
            if (words[i].length()<=p) continue;
            if (num[words[i][p]-'A']!=-1){
                rl+=num[words[i][p]-'A'];
            }
            else{
                for (int j=0;j<10;++j){
                    if (vis[j]) continue;
                    vis[j]=true;
                    rl+=j;
                    num[words[i][p]-'A']=j;
                    dfs(p,i+1,rl,words,result);
                    vis[j]=false;
                    rl-=j;
                    num[words[i][p]-'A']=-1;
                }
                return;
            }
        }
        if (result.length()<=p){
            if (rl%10==0) dfs(p+1,0,rl/10,words,result);
        }
        else if (num[result[p]-'A']!=-1){
            rr=num[result[p]-'A'];
            if (rr==rl%10) dfs(p+1,0,rl/10,words,result);
        }
        else{
            if (vis[rl%10]) return;
            rr=rl%10;
            vis[rr]=true;
            num[result[p]-'A']=rr;
            dfs(p+1,0,rl/10,words,result);
            vis[rr]=false;
            num[result[p]-'A']=-1;
        }
    }
    
public:
    bool isSolvable(vector<string>& words, string& result) {
        memset(num,-1,sizeof(num));
        memset(vis,false,sizeof(vis));
        n=result.length();
        if (result.length()>1) lead.push_back(result[0]);
        for (auto &e:words){
            n=max(n,(int)e.length());
            reverse(e.begin(),e.end());
            if (e.length()>1) lead.push_back(e[0]);
        }
        reverse(result.begin(),result.end());
        ok=false;
        dfs(0,0,0,words,result);
        return ok;
    }
};
```


[@LeetCode](/u/leetcode/)