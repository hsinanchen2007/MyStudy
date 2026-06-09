两种思路，用unordered_map记录区域对应情况，有较优的时间和空间效率。

思路一：
```c++
class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        // 建立索引，记录每个区域的父节点是哪个，父节点仅有一个
        unordered_map<string, string> index;
        for(int i = 0; i < regions.size(); i++)
            for(int j = 1; j < regions[i].size(); j++)
                index[regions[i][j]] = regions[i][0];
        // 找出每个区域的父节点路径
        vector<string> path1({region1});
        while(index.count(path1[path1.size() - 1]) > 0)
            path1.push_back(index[path1[path1.size() - 1]]);
        vector<string> path2({region2});
        while(index.count(path2[path2.size() - 1]) > 0)
            path2.push_back(index[path2[path2.size() - 1]]);
        // 路径末尾是根节点一定相同，反过来找出第一个不同之前的相同区域
        int pos = 1, n1 = path1.size(), n2 = path2.size();
        while(n1 - pos > 0 && n2 - pos > 0 && path1[n1 - pos - 1] == path2[n2 - pos - 1])
            pos++;
        return path1[n1 - pos];
    }
};
```

思路二：
```c++
class Solution {
public:
    void make_depth(unordered_map<string, string>& index, unordered_map<string, int>& depth, string aim)
    {
        if(depth.count(aim) > 0) return;
        if(index.count(aim) == 0) {depth[aim] = 0; return;}
        make_depth(index, depth, index[aim]);
        depth[aim] = depth[index[aim]] + 1; 
        return;
    }

    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        // 建立索引，记录每个区域的父节点是哪个，父节点仅有一个
        unordered_map<string, string> index;
        for(int i = 0; i < regions.size(); i++)
            for(int j = 1; j < regions[i].size(); j++)
                index[regions[i][j]] = regions[i][0];
        // 给每个节点深度，先不进行深度计算，需要的时候再计算
        unordered_map<string, int> depth;
        // 根据深度让两个区域上升到同一深度
        while(1)
        {
            if(depth.count(region1) > 0 && depth.count(region2) > 0)
            {
                if(depth[region1] < depth[region2])
                    region2 = index[region2];
                else if(depth[region1] > depth[region2])
                    region1 = index[region1];
                else
                    break;
            }
            else
            {
                make_depth(index, depth, region1);
                make_depth(index, depth, region2);
            }
        }
        // 两个区域同时上升到最小公共域
        while(region1 != region2)
        {
            region1 = index[region1];
            region2 = index[region2];
        }
        return region1;
    }
};
```

