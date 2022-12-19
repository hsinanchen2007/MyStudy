首先用一个额外的大小为1000的数组存储节点颜色，不同颜色以不同数字标识，初始化为0（未染色状态）
- 遍历边集合
1. 若首尾节点均无颜色，为它们染一个新颜色
2. 若首尾节点有一个无色，将无色节点染成有色节点的颜色
3. 若首尾节点均有颜色
    1. 若颜色相同，找到了冗余边
    2. 若颜色不同，将颜色数组中所有这两种颜色的节点都统一为一种颜色。

- C++代码如下
```
vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        vector<int> link(1001,0);
        int color0 = 0;
        int color1 = 1;
        for(int i=0;i<edges.size();i++)
        {
            if(link[edges[i][0]] == 0 && link[edges[i][1]] == 0)
                link[edges[i][0]] = link[edges[i][1]] = i+1;
            else if(link[edges[i][0]] == 0)
                link[edges[i][0]] = link[edges[i][1]];
            else if(link[edges[i][1]] == 0)
                link[edges[i][1]] = link[edges[i][0]];
            else if(link[edges[i][0]] == link[edges[i][1]])
                return edges[i];
            else
            {
                color0 = link[edges[i][1]];
                color1 = link[edges[i][0]];
                for(int i=0;i<1001;i++)
                    if(link[i] == color0)
                        link[i] = color1;
            }
        }
        return edges[edges.size()-1];
    }
```