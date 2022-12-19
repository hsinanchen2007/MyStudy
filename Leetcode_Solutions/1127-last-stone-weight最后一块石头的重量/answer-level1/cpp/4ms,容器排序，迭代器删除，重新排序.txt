### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()<=0)
        return 0;
        vector<int> v=stones;
        sort(v.begin(),v.end());
        int n=v.size();
        while(n>=2)
        {
            v[n-2]=v[n-1]-v[n-2];
            if(v[n-2]==0)
            {
                n-=2;
                auto e=v.end()-1;
                v.erase(e);
                e=v.end()-1;
                v.erase(e);
            }
            else{
                auto e=v.end()-1;
                v.erase(e);
                sort(v.begin(),v.end());
                n-=1;
            }
        }
        return v[0];
    }
};
```