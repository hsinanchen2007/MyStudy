### 解题思路
这个逻辑关系不是很复杂，应该只有6种情况，理清楚就可以了。
这个代码性能不是很好，或许可以进行一点优化。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int a_begin,b_begin,a_end,b_end;
        vector<vector<int>> ret;
        if (A.size()==0 || B.size()==0) return ret;
        int i=0,j=0;
        int sa=A.size(),sb=B.size();
        while (i<sa && j<sb)
        {        
            vector<int> t;
            a_begin=A[i][0]; a_end=A[i][1];
            b_begin=B[j][0]; b_end=B[j][1];
            if (a_begin<=b_begin) 
                if (a_end>= b_begin)
                    t.push_back(b_begin);
                else
                {
                    i++;
                    continue;
                }
            else
                if (b_end>=a_begin)
                    t.push_back(a_begin);
                else
                {
                    j++;
                    continue;
                }

            if (a_end<=b_end) 
            {
                t.push_back(a_end);
                i++;
            }
            else 
            {
                t.push_back(b_end);
                j++;
            }
            ret.push_back(t);
        }
        return ret;

    }
};
```