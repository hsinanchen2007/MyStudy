```
class Solution {
public:
    int len;
    bool flag;
    string tmp,res;
    vector<string> ans;
    unordered_map<string,int> vis;//标记访问过程中边的剩余量
    unordered_map<string,set<string>> mp;//记录边,第二项要排序这样找到的第一个解就是正解（大大节省时间）
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        len = tickets.size();
        for(auto&it:tickets) {
            mp[it[0]].insert(it[1]);
            vis[it[0]+it[1]]++;
        }
        vis["JFK"] = 1;
        dfs("","JFK",0);
        for(int i=0;i<res.length();i+=3) ans.push_back(string(res.begin()+i,res.begin()+i+3));
        return ans;
    }
    void dfs(string last,string site,int cnt) {
        if(!vis[last+site]||res!="") return;//如果这条边已经使用完毕或者已经找到解就不需要继续访问了
        tmp += site;
        vis[last+site]--;
        for(auto&next:mp[site]) dfs(site,next,cnt+1);
        if(cnt==len) res = tmp; 
        vis[last+site]++;
        tmp.erase(tmp.end()-site.length(),tmp.end());  
    }
};
```
