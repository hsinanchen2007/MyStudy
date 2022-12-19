### 解题思路
这道题的重点就是获得每层有哪些人，可以用BFS，并设置一个标记，每次队列走到标记就代表走完这一层了。同时标记设置为队尾，就正好是下一层的尾部。
我使用map保留每层的信息，其实直接到目标层就可以了，循环也可以在这时结束。最后排序输出就好了。

### 代码

```cpp
class Solution {
public:
   
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = watchedVideos.size();
        vector<bool> vis(n, true);
        queue<int> q;
        q.push(id);
        vis[id]=false;
        map<string,int> mp;
        vector< map<string,int> > res(n+1,mp);
        int last=id;
        int j=0;
        while (!q.empty()) {
            
            int temp = q.front(); q.pop();
          
            for(int q=0;q<watchedVideos[temp].size();q++)
            {
                res[j][watchedVideos[temp][q]]++;
            }
            
            for(int i=0;i<friends[temp].size();i++)
            {
                if(vis[friends[temp][i]]==true)
                {
                   q.push(friends[temp][i]);
                   vis[friends[temp][i]]=false;
                   
                } 
            }
         
            if (temp==last)
            {
                j++;
                last =q.back();
            }
      
        }
        
        vector<string> res1;
        vector<pair<string, int>> vec(res[level].begin(), res[level].end());
     
	   for(int x=0;x<vec.size()-1;x++)
        for(int y=0;y<vec.size()-x-1;y++)
        {
            if(vec[y].second>vec[y+1].second)
            {
                pair<string, int> xy=vec[y];
                vec[y]=vec[y+1];
                vec[y+1]=xy;
            }
        }
	    for (int i = 0; i < vec.size(); ++i)
	    {
		    cout << vec[i].first << " " << vec[i].second<< endl;
            res1.push_back(vec[i].first);
        }
        
        
        return res1;


    }
};
```