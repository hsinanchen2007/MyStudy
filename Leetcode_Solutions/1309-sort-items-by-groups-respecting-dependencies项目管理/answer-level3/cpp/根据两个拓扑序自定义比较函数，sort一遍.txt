### 解题思路
思路同题解中大佬的双层拓扑排序，不过通过sort自定义比较等级，一次排序实现。要注意检查两个拓扑序是否冲突。

### 代码

```cpp
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0;i<group.size();++i)
        {
            if(group[i] == -1)
                group[i] = m++;
        }

        vector<unordered_set<int>> groupAdj(m);
        vector<int> groupInds(m, 0);
        vector<vector<int>> projAdj(n);
        vector<int> projInds(n);
        for(int pC = 0;pC<n;++pC)
        {
            const auto& ps = beforeItems[pC];
            projInds[pC] = ps.size();
            int gC = group[pC];
            for(auto pP: ps)
            {
                projAdj[pP].push_back(pC);
                int gP = group[pP];
                if(gP!=gC && groupAdj[gP].count(gC) == 0)
                {
                    groupAdj[gP].insert(gC);
                    ++groupInds[gC];
                }
            }
        }

        vector<int> heriG(m, 0), heriGP(n, 0);
        int cnt = 0;
        queue<int> q;
        for(int i=0;i<m;++i)
        {
            if(groupInds[i] == 0)
                q.push(i);
        }
        while(!q.empty() && cnt < m + 1)
        {
            auto gId = q.front();
            q.pop();
            heriG[gId] = cnt++;
            for(auto adj: groupAdj[gId])
            {
                --groupInds[adj];
                if(groupInds[adj] == 0)
                    q.push(adj);
            }
        }
        if(!q.empty() || cnt != m)
            return vector<int>();

        for(int i=0;i<n;++i)
            heriGP[i]=heriG[group[i]];
        
        cnt = 0;
        vector<int> heriP(n, 0);
        for(int i=0;i<n;++i)
        {
            if(projInds[i] == 0)
                q.push(i);
        }
        while(!q.empty() && cnt < n+1)
        {
            auto pId = q.front();
            q.pop();
            heriP[pId] = cnt++;
            for(auto adj: projAdj[pId])
            {
                --projInds[adj];
                if(projInds[adj] == 0)
                    q.push(adj);
            }
        }
        if(!q.empty() || cnt != n)
            return vector<int>();

        for(int i=0;i<n;++i)
        {
            const auto& before = beforeItems[i];
            int hGi = heriGP[i];
            for(auto b: before)
            {
                //cout << i << " " << hGi << " " << b << " " << heriGP[b] << endl;
                if(hGi < heriGP[b])
                    return vector<int>();
            }
        }

        vector<int> sortTable(n);
        iota(sortTable.begin(), sortTable.end(), 0);
        sort(sortTable.begin(), sortTable.end(), [&heriGP, &heriP](int i1, int i2){
            return heriGP[i1]>heriGP[i2]?false:
                        heriGP[i1]<heriGP[i2]?true:heriP[i1]<heriP[i2];
        });

        return sortTable;
    }
};
```