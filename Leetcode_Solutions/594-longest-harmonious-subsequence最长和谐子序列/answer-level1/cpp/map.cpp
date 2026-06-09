### 解题思路

### 代码

```cpp
class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        map<int, int> mp;
        for(int i = 0 ; i < nums.size() ; ++i)
            mp[nums[i]]++;
        int maxx = 0;
        map<int,int>::iterator i = mp.begin();
        map<int,int>::iterator j = mp.begin();
        i++;
        for(; i != mp.end() ; ++i)
        {
            if(i->first - j->first == 1)
                maxx = max(maxx, i->second + j->second);
            j++;
        }
        return maxx;
    }
};
```