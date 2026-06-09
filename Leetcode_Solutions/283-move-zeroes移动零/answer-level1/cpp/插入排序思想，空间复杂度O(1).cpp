```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    
        for(int i = 1; i < nums.size(); i++)
        {
            int key = nums[i];
            int j = i - 1;
            while(j >=0 && key && nums[j] == 0)
            {
                nums[j + 1] = nums[j];
                j --;
            }
            nums[j + 1] = key;
        }
    }
};
```
