### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> se;
        int min=10000;
        for(auto cur:deck)
        {
            ++se[cur];
            
        }

        for(auto cur:se)
        {
            if(cur.second<min)
            min=cur.second;
        }

        cout<<"min:"<<min<<endl;
        for(int i=2;i<=min;++i)
        {
            bool sym=true;
            for(auto cur:se)
            {
                if(cur.second%i)
                {
                    sym=false;
                    break;
                }
            }

            if(sym)
            return true;


        }

        return false;

    }
};
```