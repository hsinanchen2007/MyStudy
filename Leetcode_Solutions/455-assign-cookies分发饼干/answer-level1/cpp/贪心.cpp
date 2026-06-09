### 解题思路
孩子胃口数 1,2,3
饼干大小数 1，1    
如果孩子胃口数小于饼干大小，一个孩子被满足
### 代码

```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int g_child=0;       //满足了几个孩子
        int s_cake=0;       //用掉了几个饼干

        while (g_child < g.size()&& s_cake < s.size())
        {  //孩子或饼干都没有被尝试完
            if(g[g_child] <= s[s_cake])
            {  
                //说明孩子可以被满足，被满足的孩子数加一    
                g_child++;    
            }
            s_cake++;               //不管孩子有没有被满足，都要换下一个饼干尝试。
         }
        return g_child;
    }
};
```