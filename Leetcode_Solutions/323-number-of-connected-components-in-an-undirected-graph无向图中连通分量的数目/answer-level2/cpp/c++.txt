### 解题思路
此处撰写解题思路
![截图.PNG](https://pic.leetcode-cn.com/0415793aad36a843c91653a4ef6f6d1675cc70e62c587b38ec1d4d6517fd87fa-%E6%88%AA%E5%9B%BE.PNG)

用并查集判断.
### 代码

```cpp
class Solution {
    vector<int> _parent;
    int findparent(int x)
    {
        if(x == _parent[x])
            return x;
        else
            return  _parent[x] = findparent(_parent[x]);
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        _parent.resize(n);
        for(int i  = 0; i < n; i++)
        {
            _parent[i] = i;
        }
        for(auto val: edges)
        {
            int px = findparent(val[0]);
            int py = findparent(val[1]);
            if(px != py)
            {
                _parent[py] = px;
            }
        }
        int res = 0; 
        for(int i = 0; i < n; ++i)
        {
            if(_parent[i] == i) res++;
        }
        return res;
    }
};
```