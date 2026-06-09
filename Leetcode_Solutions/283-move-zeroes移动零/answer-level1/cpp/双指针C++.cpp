(1),Alias two pointers, curPos indicates the current position,
    zeroPos illustrates the first position of number zero.
(2),Iterator the whole array from the left to right.

```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
            (1),Alias two pointers, curPos indicates the current position,
            zeroPos illustrates the first position of number zero.
            (2),Iterator the whole array from the left to right.

        */
        int len = nums.size();
        if(len == 1){
            return;
        }
        int zeroPos, curPos, tmp;
        zeroPos = 0;
        while(zeroPos < len && nums[zeroPos] != 0){
            zeroPos++;
        }
        for(curPos = zeroPos + 1; curPos < len; ++curPos){
            if(nums[curPos] != 0){
                nums[zeroPos] = nums[curPos];
                nums[curPos] = 0;
                zeroPos++;
            }
        }
    }
};
```


