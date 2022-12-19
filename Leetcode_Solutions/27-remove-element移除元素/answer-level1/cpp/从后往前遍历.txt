```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lenth = nums.size();
        int i = 0;
        int curindex = lenth-1;
        int reslenth = lenth;
        while(curindex !=-1)
        {
            if(val == nums[curindex])
            {
                for(i=curindex;i<reslenth-1;i++)
                {
                    nums[i] = nums[i+1];
                }
                reslenth--;
              
            }
            curindex--;
        }
        return reslenth;
    }
};
```
