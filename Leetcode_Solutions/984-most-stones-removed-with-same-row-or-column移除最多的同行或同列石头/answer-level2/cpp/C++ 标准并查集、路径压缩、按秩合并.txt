### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int>fa;
    // 集合里代表元素的秩
    map<int,int>rank;
    int find(int x)
    {
        int t = x;
        while(x!=fa[x]) x = fa[x];
        // 路径压缩
        while(t!=x)
        {
            int z = fa[t];
            fa[t] = x;
            t = z;
        }
        return x;
    }
    void Union(int x,int y)
    {
        int fa_x = find(x);
        int fa_y = find(y);
        // 按秩合并
        if(fa_x!=fa_y)
        {
            int big = rank[fa_x]>rank[fa_y] ? fa_x:fa_y;
            int small = big==fa_x ? fa_y:fa_x;
            fa[small] = big;
            rank[big] += rank[small];
            rank.erase(small);
        }
    }
    // 标记横坐标值出现的位置
    unordered_map<int,int>row;
    //  标记纵坐标值出现的位置
    unordered_map<int,int>col;
    
    int removeStones(vector<vector<int>>& stones) {
        // 每个坐标点(x,y)对应一个位置，同行同列的位置合并
        if(stones.empty()) return 0;
        int n = stones.size();
        fa.resize(n);
        for(int i=0;i<n;++i) 
        {
            fa[i]=i;
            rank[i] = 1;
        }
        for(int i=0;i<stones.size();++i)
        {
            vector v = stones[i];
            // 横纵坐标均是第一次出现 记录位置
            if(!row.count(v[0]) && !col.count(v[1]))
            {
               
                row[v[0]] = i;
                col[v[1]] = i;
               
            }
            // 横坐标出现过，将当前位置同之前出现该值的位置合并
            else if(row.count(v[0]) && !col.count(v[1]))
            {
                col[v[1]] = i;
                Union(row[v[0]],i);
            }
            // 纵坐标出现过，同理
            else if(!row.count(v[0]) && col.count(v[1]))
            {
                row[v[0]] = i;
                Union(i,col[v[1]]);
            }
            // 横纵坐标均出现过
            else
            {
                Union(row[v[0]],i);
                Union(col[v[1]],i);
            }
        }
        int ans = 0;
        //for(auto t = rank.begin();t!=rank.end();t++)
        //    cout<<t->first<<" "<<t->second<<endl;
        // 注意是每一个集合里都可以移与其他同行同列的
        // 即n个元素的集合能移动n-1次
        for(auto& it:rank)
        {
            ans+=it.second-1;
        }
        return ans;
    }
};
```