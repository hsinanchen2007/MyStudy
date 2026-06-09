题目没有要求元素排列顺序，所以用双指针，检查到奇数就直接跟low指针指向的那个数调换位置。
```
class Solution {
    public int[] exchange(int[] nums) {
        int fast = 0;
        int low = 0;
        int temp = 0;
        int len = nums.length;
        int cur = 0;
        while(fast<len){
            if(nums[fast]%2 ==1){
                temp = nums[low];
                nums[low] = nums[fast];
                nums[fast] = temp;
                low++;
            }
            fast++;
        }
        return nums;
    }
}
```
