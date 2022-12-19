### 解题思路
双指针，(首项+尾项数)*项数/2；

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int> >res;
        int plow=1,phigh=2;
        while(plow<phigh)
        {
            int cur=(phigh+plow)*(phigh-plow+1)/2;
            if(cur<target)  phigh++;
            if(cur==target)
            {
                vector<int>ans;
                for(int i=plow;i<=phigh;i++)
                    ans.push_back(i);
                res.push_back(ans);
                plow++;
            }
            if(cur>target)  plow++;
        }
        return res;
    }
};
```