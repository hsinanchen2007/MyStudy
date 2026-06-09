### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :9.7 MB, 在所有 C++ 提交中击败了91.71%的用户
并查集方法，关键思路是：顺序连接，遇到两个连接点的根节点相同的情况就连成环了，输出这俩节点即可。
### 代码

```cpp
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int length=edges.size();
        vector<int> result;
        result.push_back(0);
        for(int i=0;i<length;i++)
        {
            int max=(edges[i][0]<edges[i][1]?edges[i][1]:edges[i][0]);
            if(result.size()-1<max)
            {
                for(int j=result.size();j<=max;j++) result.push_back(j);
            }
            if(unionpq(result,edges[i][0],edges[i][1])) return edges[i];

        }
        vector<int> a;       
        return a;
    }
    int unionpq(vector<int>& v,int p,int q)
    {
        if(root(v,p)==root(v,q))return 1;
        v[root(v,p)]=root(v,q);
        return 0;
    }
    int root(vector<int>& v,int i)
    {
        if(v[i]!=i)
        {
            i=v[i];
            return root(v,i);
        }
        else
        {
            return i;
        }
    }
};
```