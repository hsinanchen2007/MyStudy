解法1：从后往前遍历数组，遇到0则把0后面的非0 数字向前移动，通过count值来定位后面要移动的非0数字的个数
```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==0){
                for(int j=i;j<nums.size()-count-1;j++){
                    nums[j]=nums[j+1];
                }
                nums[nums.size()-count-1]=0;
                count++;
            }
        }
        
    }
};
```
解法2：快慢指针,快指针遍历数组，慢指针记录非0数字
```
class Solution {
public:
   void moveZeroes(vector<int>& nums) {
    int lastNonZeroFoundAt = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[lastNonZeroFoundAt++] = nums[i];
        }
    }
    
    for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
        nums[i] = 0;
    }
}
};

//作者：LeetCode
//链接：https://leetcode-cn.com/problems/move-zeroes/solution/yi-dong-ling-by-leetcode/
```