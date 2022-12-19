```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int insertPos = -1;
        if( find(nums.begin(), nums.end(), target) != nums.end() )
            return find(nums.begin(), nums.end(), target) - nums.begin();
        else{
            for(int i=0; i<nums.size(); i++){
                if(nums[i] < target) continue;
                else{
                    insertPos = i;
                    break;
                }
            }
        }
        return insertPos==-1 ? nums.size() : insertPos;
    }
};
```
