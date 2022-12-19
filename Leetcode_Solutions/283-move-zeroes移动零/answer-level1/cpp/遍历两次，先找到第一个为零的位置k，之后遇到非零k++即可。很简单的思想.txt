```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i]==0) {
                k = i; //找到第一个零的位置
                break;
            }
        }
        for(int i = k; i < nums.size(); ++i) {
            if(nums[i]!=0) {
                nums[k++] = nums[i];    //遇到非零元素覆盖nums[k]
                if(k-1 != i) nums[i] = 0; //注意这种特殊情况！
            }
        }
    }
};[]()
```
