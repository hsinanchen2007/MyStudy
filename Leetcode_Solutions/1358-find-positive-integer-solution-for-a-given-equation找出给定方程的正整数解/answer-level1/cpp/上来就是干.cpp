
![image.png](https://pic.leetcode-cn.com/a7c3d2e759c38bd4eee5df8c9afff6c039eda8e757d50e695769b736897bf7a7-image.png)

```
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        
        for(int x=1;x<=1000;x++)
        {
            for(int y=1;y<=1000;y++)
            {
                if(customfunction.f(x,y)==z)
                {
                    vector<int> tmp;
                    tmp.push_back(x);
                    tmp.push_back(y);
                    res.push_back(tmp);
                }
            }
        }
        
        return res;
    }
};

```