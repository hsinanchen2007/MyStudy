### 解题思路
将孩子的胃口和饼干的尺寸都从小到大排序好。分别从第一个孩子和第一块饼干开始比较，若这个孩子的胃口小于这块饼干的尺寸，则得到满足的孩子数+1，接着比较下一个孩子与下一块饼干。若这个孩子的胃口大于这块饼干，则拿下一块饼干的尺寸与这个孩子的胃口进行比较，直到找出比这个孩子的胃口大的饼干或者没有饼干了。

### 代码

```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int j=0;
        int num=0;
        for(int i=0;i<g.size();i++)
        {
            for(;j<s.size();j++)
            {
                if(g[i]<=s[j])
                {
                    num++;
                    j++;
                    break;
                }
            }
        }
        
        return num;

    }
};
```