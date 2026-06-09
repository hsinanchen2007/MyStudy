### 解题思路

[@liouzhou_101](/u/liouzhou_101/)的方法
map<char, map<int, int>> f; 将每个字母和他的排名信息储存
f[s[i]][i]++; 统计每个名词的个数
然后利用sort进行排序
### 代码

```cpp
class Solution {
public:
    
    string rankTeams(vector<string>& votes) {
        int m = votes.size();
        string v = votes[0];
        map<char, map<int, int>> f;
        for(auto s : votes){
            for(int i = 0; i < s.size(); i++)
                f[s[i]][i]++;
        }
        sort(v.begin(),v.end(), [&](char a, char b) ->bool{
            for(int i = 0; i < v.size();i++){
                if(f[a][i] > f[b][i]) return 1;
                if(f[a][i] < f[b][i]) return 0;
            }
            return a < b; // 若1，往前面排
            );
        return v;
    }
};

```