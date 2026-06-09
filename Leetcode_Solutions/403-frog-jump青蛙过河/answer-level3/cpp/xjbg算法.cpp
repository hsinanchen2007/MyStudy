### 解题思路
此处撰写解题思路
map的思想，将可能的跳的步数加到能跳到的石头上，每个石头便利这个表，然后往后更新，最主要的是要判重，，，这是最关键的，不然tle，
### 代码

```cpp
class Solution {
public:
    bool canCross(vector<int>& stones) {
int k=1;
if(stones.size()==2){
    if(stones[1]==1)
    return true;
    return false;
}
map<int,int>flag;
map<int,int>rev;
vector<vector<int>> mp;
for(int i=0; i<stones.size(); i++ )
{
    
    vector<int> tmp;
    mp.push_back(tmp);
    
    rev[stones[i]]=i;

}


for(int i=1; i<stones.size(); i++ )
flag[stones[i]]=1;
mp[1].push_back(1);

for(int i=1; i<stones.size()-1; i++ ){
    //if(i==6&&mp[6][0]==2&&mp[6][1]==2&&mp[i].size()==2)
//return true;
map<int,int>tps;
for(int j=0;j<mp[i].size(); j++){
    if(tps[mp[i][j]]==1)
        continue;
    else
        tps[mp[i][j]]=1;
    if(mp[i][j]>0&&flag[stones[i]+mp[i][j]]==1)
        mp[rev[stones[i]+mp[i][j]]].push_back(mp[i][j]);
    if(mp[i][j]-1>0&&flag[stones[i]+mp[i][j]-1]==1)
        mp[rev[stones[i]+mp[i][j]-1]].push_back(mp[i][j]-1);
    
    if(mp[i][j]+1>0&&flag[stones[i]+mp[i][j]+1]==1)
        mp[rev[stones[i]+mp[i][j]+1]].push_back(mp[i][j]+1);
    
}
//if(i==5&&mp[5][0]==2&&mp[5][1]==2)
//return true;


}

if(mp[stones.size()-1].size()==0)
return false;
return true;
    }
};
```