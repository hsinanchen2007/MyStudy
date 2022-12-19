![屏幕快照 2020-02-25 下午4.57.26.png](https://pic.leetcode-cn.com/db7ba0e00eb5e0918ae9ee4bd3a6317de495573ae1a768b17eaf77e986cab394-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-25%20%E4%B8%8B%E5%8D%884.57.26.png)

**如果没有重复数字，那么正常排序后，数字i应该在下标为i的位置，所以思路是重头扫描数组，遇到下标为i的数字如果不是i的话，（假设为m),那么我们就拿与下标m的数字交换。在交换过程中，如果有重复的数字发生，那么终止返回ture**


```
class Solution {
    public int findRepeatNumber(int[] nums) {
        int temp;
        for(int i=0;i<nums.length;i++){
            while (nums[i]!=i){
                if(nums[i]==nums[nums[i]]){
                    return nums[i];
                }
                temp=nums[i];
                nums[i]=nums[temp];
                nums[temp]=temp;
            }
        }
        return -1;
    }
}
```


