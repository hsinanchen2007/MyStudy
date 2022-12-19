1. 关于复杂度
    1.1 时间复杂度为O(n)
    1.2 空间负责度为O(1)
2. 我的解题思路
    2.1 循环遍历数组，有三种情况
        2.1.1 nums[i]>=nums[i-1],符合题意
        2.1.2 nums[i-2]>nums[i],表示nums[i-1]会小于nums[i-2],所以我们将nums[i]设置为nums[i-1]
        2.1.3 nums[i-2]<=nums[i],将nums[i-1]设为nums[i]会符合题意
<br />
### java实现
```
class Solution{

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 circulate array from head to tail,there have three condition
     *         2.1.1 nums[i]>=nums[i-1],conform to topic's mean
     *         2.1.2 nums[i-2]>nums[i],it means nums[i-1] will be smaller than nums[i-2],so we set nums[i] to nums[i-1]
     *         2.1.3 nums[i-2]<=nums[i],set nums[i-1] to nums[i] will conform topic's mean
     * 3.About submit record
     *     3.1 2ms and 49.5MB memory in LeetCode China
     *     3.2 1ms and 46.2MB memory in LeetCode
     * 4.Q&A
     *
     * @param nums
     * @return
     */
    public boolean checkPossibility(int[] nums) {
        if(nums==null||nums.length<2){
            return true;
        }
        int flag=0;
        for(int i=1,length=nums.length;i<length&&flag<2;i++){
            if(nums[i]>=nums[i-1]){
                continue;
            }
            flag++;
            if(i-2>=0&&nums[i]<nums[i-2]){
                nums[i]=nums[i-1];
            }
            else{
                nums[i-1]=nums[i];
            }
        }
        return flag<2;
    }
}
```

### php实现
```
class Solution{

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 circulate array from head to tail,there have three condition
     *         2.1.1 nums[i]>=nums[i-1],conform to topic's mean
     *         2.1.2 nums[i-2]>nums[i],it means nums[i-1] will be smaller than nums[i-2],so we set nums[i] to nums[i-1]
     *         2.1.3 nums[i-2]<=nums[i],set nums[i-1] to nums[i] will conform topic's mean
     * 3.About submit record
     *     3.1 50ms and 15.9MB memory in LeetCode China
     *     3.2 56ms and 16.2MB memory in LeetCode
     * 4.Q&A
     *
     * @param nums
     * @return
     */
    function checkPossibility($nums) {
        if(!isset($nums) || count($nums) < 2){
            return true;
        }
        $flag = 0;
        for($index = 1, $len = count($nums); $index < $len && $flag < 2; $index++){
            if($nums[$index] >= $nums[$index - 1]){
                continue;
            }
            $flag++;
            if($index - 2 >= 0 && $nums[$index] < $nums[$index - 2]){
                $nums[$index] = $nums[$index - 1];
            }
            else{
                $nums[$index - 1] = $nums[$index];
            }
        }
        return $flag < 2;
    }
}
```

如果你有更好的想法或者疑问，可以到[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)提出issue，我会及时处理
你也可以关注[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)获得其他题目解题思路
