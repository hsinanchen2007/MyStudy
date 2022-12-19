### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> s;
        for(int i=0;i<nums.size();i++){
            set<int>::iterator it=s.lower_bound(nums[i]);
            if(it!=s.end() && (*it)==nums[i]){
                return true;
            }
            s.insert(nums[i]);
            if(s.size()>k){
                s.erase(nums[i-k]);
            }
        }
        return false;
    }
};
```