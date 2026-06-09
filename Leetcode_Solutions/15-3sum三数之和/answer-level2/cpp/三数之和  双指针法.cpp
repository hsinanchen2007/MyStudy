
```cpp []
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int len = nums.size();
        vector<vector<int>> ret;
        map<int, bool> his;
        sort(nums.begin(), nums.end());

        for(int i = 0; i <len; i++)
        {

            if(nums[i] > 0)break;
            if(his.count(nums[i]) > 0) continue;
            his.insert(map<int, bool>::value_type(nums[i], true));
            
            int lptr = i + 1;
            int rptr = len - 1;
            
            while (lptr < rptr)
            {
                if(nums[lptr] + nums[rptr] + nums[i] == 0) 
                {
                    ret.push_back({nums[i], nums[lptr], nums[rptr]});
                    do
                    {
                        rptr--;
                    } while (nums[rptr+1] == nums[rptr] && rptr > lptr);                    
                    do
                    {
                        lptr++;
                    } while (nums[lptr-1] == nums[lptr] && rptr > lptr);
                }
                else if(nums[lptr] + nums[rptr] + nums[i] >0)
                {
                    do
                    {
                        rptr--;
                    } while (nums[rptr+1] == nums[rptr] && rptr > lptr);
                }else
                {
                    do
                    {
                        lptr++;
                    } while (nums[lptr-1] == nums[lptr] && rptr > lptr);
                }
            }
            
        }
        return ret;

    }
};
```
