### 解题思路


### 代码

```cpp
class Solution{
public:
    vector<vector<int>> findContinuousSequence(int target){
        vector<vector<int>> vec;
        vector<int> res;
        for(int l=1,r=2;l<r;){
            int sum=(l+r)*(r-l+1)/2;
            if(sum==target){
                res.clear();
                for(int i=l;i<=r;++i) res.emplace_back(i);
                vec.emplace_back(res);
                ++l;
            }
            else if(sum<target) ++r;
            else ++l;
        }
        return vec;
    }
};
```