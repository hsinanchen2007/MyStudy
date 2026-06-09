设一个二维数组，第一维表示第几个人，第二位放在每个位置出现的次数
根据出现的次数排序喽，顺便学了一波匿名函数骚操作
```
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> paihang(26,vector<int>(26,0));
        int n = votes[0].size();
        for(int i = 0; i < votes.size();i++){
            for(int j = 0; j < n;j++)
                paihang[votes[i][j] - 'A'][j]++;
        }
        string res = votes[0];
        sort(res.begin(),res.end(),[&](char a,char b) -> bool{
            for(int i = 0; i < paihang.size();i++){
                if(paihang[a-'A'][i]>paihang[b-'A'][i]) return true;
                if(paihang[a-'A'][i]<paihang[b-'A'][i]) return false;
            }
            return a < b;
        });
        return res;
    }
};
```
