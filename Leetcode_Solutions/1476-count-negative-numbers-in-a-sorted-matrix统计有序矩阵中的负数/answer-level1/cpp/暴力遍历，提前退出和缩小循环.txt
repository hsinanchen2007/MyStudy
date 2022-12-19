
### 代码

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int s=0;
        int pre=0;
        for(auto it=grid.begin();it <grid.end();it++)
        {
            auto itit=it->begin();
        for(;itit <it->end()-pre;itit++)
            {
                if(*itit<0)
                break;
            }
            pre=it->end()-itit;
            s+=pre;
        }
        return s;
    }
};

```