
```c++
class Solution {
public:
    vector<int>father;
    int find(int x){
         return x == father[x] ? x : father[x] = find(father[x]);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        string res = s;
        father = vector<int>(n);
        for(int i=0;i<n;i++)father[i]=i;
        for(auto &c:pairs){
            int xf = find(c[0]),yf = find(c[1]);
            if(xf != yf){
                father[yf] = father[xf];
            }
        }
        vector<vector<int>>group(n);//位置
        vector<vector<char>>sgroup(n);//对应字符
        vector<int>ROOT;
        for(int i=0;i<n;i++){
            int fa = find(i);
            if(fa == i)ROOT.push_back(i);
            group[fa].push_back(i);
            sgroup[fa].push_back(s[i]);
        }
        for(auto &i:ROOT){
            int k = group[i].size();  
            sort(sgroup[i].begin(),sgroup[i].end());
            for(int j=0;j<k;j++){
                res[group[i][j]] = sgroup[i][j];
            }
        }
        return res;
    }
};
```