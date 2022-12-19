### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        if(nums.size() ==0){
            return res;
        }

        set<int> hash;
        sort(nums.begin(),nums.end());
        int size = nums.size();
        int maxN = nums[size-1];
        int min = nums[0];
        for(int i = 0;i<nums.size();i++){
            hash.insert(nums[i]);
        }
        for(int i =1;i<=size;i++){
            if(!hash.count(i)){
                res.push_back(i);
            }
        }
        return res;
    }
};
```