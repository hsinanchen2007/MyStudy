### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int> q;
        vector<string> ans;
        if(watchedVideos.size() == 0 || friends.size() == 0)
            return ans;
        q.push(id);
        vis[id]++;
        int lay = 0;
        while(!q.empty())
        {
            int k = q.size();
            if(lay == level)
            {
                for(int i = 0 ; i < k ; ++i)
                {
                    int f = q.front();
                    q.pop();
                    for(int j = 0 ; j < watchedVideos[f].size() ; ++j)
                        mp[watchedVideos[f][j]]++;
                }
                break;
            }
            for(int i = 0 ; i < k ; ++i)
            {
                int f = q.front();
                q.pop();
                for(int j = 0 ; j < friends[f].size() ; ++j)
                {
                    if(vis[friends[f][j]] == 0)
                        q.push(friends[f][j]);
                    vis[friends[f][j]]++;
                }
            }
            lay++;
        }
        vector<node> v;
        for(auto i : mp)
            v.push_back(node(i.first, i.second));
        sort(v.begin(), v.end());
        for(auto ele : v)
            ans.push_back(ele.s);
        return ans;
    }
private:
        unordered_map<string, int> mp;
        unordered_map<int, int> vis;
        struct node{
            string s;
            int cnt;
            node(string _s, int _cnt):s(_s), cnt(_cnt){}
            friend bool operator < (node a, node b)
            {
                if(a.cnt == b.cnt)
                    return a.s < b.s;
                else
                    return a.cnt < b.cnt;
            }
        };
};
```