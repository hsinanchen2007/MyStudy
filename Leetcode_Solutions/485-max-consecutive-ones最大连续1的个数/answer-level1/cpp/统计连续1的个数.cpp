```
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int m = 0;
        while(i<nums.size())
        {
            while(i<nums.size() && nums[i] == 0)
            {
                i++;
            }
            j = i;
            while(j<nums.size() && nums[j] == 1)
            {
                j++;
            }
            if(j-i>m)
            {
                m = j-i;
            }
            i = j+1;
        }
        return m;
    }
};
```
