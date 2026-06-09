### 解题思路
此处撰写解题思路
题目中最小路劲为K的friends，当在level = k的时候，访问到节点的最小路径<= k,使用一个辅助变量visit控制的k-1之前有没有访问到。
### 代码

```cpp
class Solution {
public:
    typedef struct 
    {
        string video;
        int num;
    } cell;
    
    static bool compare( const cell& cell1 , const cell& cell2)
    {
        if (cell1.num != cell2.num)
            return cell1.num < cell2.num;
        return cell1.video < cell2.video;
    }
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector <int> p,q;
        vector <bool> hasVisit;
        hasVisit.resize(friends.size() , false);
        p.push_back(id);
        hasVisit[id] = true;
        int i = 0;
        while( i < level)
        {
            q = p;
            p.resize(0);
            for (int j : q)
            {
                //if (j == id) continue;
                //p.insert(p.end() ,friends[j].begin() , friends[j].end());
                for(int k : friends[j])
                {
                    if ( !hasVisit[k] )
                    {
                        hasVisit[k] = true;
                        p.push_back(k);
                    }
                }
            }
            i++;
        }
    
        map<string, int> ansMap;
        set <int> curFriend;
        for ( int j : p )
        {
            //cout<<"j ="<<j<<endl;
            if (curFriend.find(j) != curFriend.end() || j == id)
                continue;
            curFriend.insert(j);
            for(string k : watchedVideos[j])
            {
                ansMap[k]++;
            }
        }
        vector <cell> cells;
        for ( map<string, int>::iterator it = ansMap.begin() ; it != ansMap.end() ; ++it)
        {
            cell cell1;
            cell1.video = it->first;
            cell1.num = it->second;
            cells.push_back(cell1);
        }
        
        sort(cells.begin() , cells.end() ,compare);
        vector <string> ans;
        for (cell j : cells)
        {
            ans.push_back(j.video);
        }
        return ans;
    }
};
```