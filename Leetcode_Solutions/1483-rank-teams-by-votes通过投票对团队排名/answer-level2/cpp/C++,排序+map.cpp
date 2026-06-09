```
const int maxn=1e4+10;
map<char,vector<int>>mp;
int m;
inline bool cmp(char &a,char &b){
    for(int i=0;i<min(m,26);i++){
        if(mp[a][i]>mp[b][i])return true;
        if(mp[a][i]<mp[b][i])return false;//这一步不能少！！！
    }
    return a<b;
    //下面这种比较的方法也是可以的，这是map的一种特性，数组vector内部从第一个元素开始往后自动一个一个比较。。。
    //return mp[a]==mp[b]?a<b:mp[a]>mp[b];
}
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n=votes.size();
        m=votes[0].size();
        for(auto v:votes[0]){
            mp[v]=vector<int>(m,0);//这一步是进行初始化的步骤。。。
        }
        for(auto v:votes){
            for(int i=0;i<m;i++){
                mp[v[i]][i]++;//这个表示的是，mp的二维map表示的是v[i]的字符排名在第i位有多少个。。。
            }
        }
        string res=votes[0];
        sort(res.begin(),res.end(),cmp);
        return res;
    }
};
```
