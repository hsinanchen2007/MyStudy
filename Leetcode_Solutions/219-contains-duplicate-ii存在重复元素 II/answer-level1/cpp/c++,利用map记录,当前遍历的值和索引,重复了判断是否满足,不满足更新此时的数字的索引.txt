### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i])==0){
                m.insert(std::make_pair(nums[i],i));
            }
            else{
                int index=m[nums[i]];
                if(abs(index-i)<=k){
                    return true;
                }
                else{
                    m[nums[i]]=i;
                }
            }
        }
        return false;
    }
};
```