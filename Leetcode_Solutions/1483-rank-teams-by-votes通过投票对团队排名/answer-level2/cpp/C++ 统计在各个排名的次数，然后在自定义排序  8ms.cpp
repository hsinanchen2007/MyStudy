```cpp
int len,n;
int cnt[26+1][1005];
bool cmp(int a,int b){
    for(int i=0;i<n;i++){
        if(cnt[a][i]!=cnt[b][i]) return cnt[a][i]>cnt[b][i];
    }
    return a<b;
}
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        memset(cnt,0,sizeof(cnt));
        len = votes.size(),n = votes[0].length();
        if(len==1||n==1) return  votes[0];
        for(int i=0;i<len;i++){
            for(int j=0;j<n;j++){
                cnt[votes[i][j]-'A'][j]++;
            }
        }
        vector<int> ch(n);
        for(int i=0;i<n;i++){
            ch[i] = votes[0][i]-'A';
        }
        sort(ch.begin(),ch.end(),cmp);
        string res;
        for(int i=0;i<n;i++){
            res += 'A'+ch[i];
        }
        return res;
    }
};
```
