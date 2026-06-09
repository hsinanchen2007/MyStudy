1. 关于复杂度
   1.1 时间复杂度为 O(n)
   1.2 空间负责度为 O(1)
2. 我的解题思路
   2.1 循环遍历数组将所有数加到 right 变量中
   2.2 先用首元素减掉 right 变量，然后跟 left 变量对比
   2.3 循环遍历数组，不断减掉 right 变量以及加上 left 变量，对比返回
<br />
### java实现
```
class Solution{

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 circulate array first fill all num to variable right
     *     2.2 subtract right with first num and compare with current variable left
     *     2.3 circulate array,subtract variable right and increase variable left and compare
     * 3.About submit record
     *     3.1 2ms and 39MB memory in LeetCode China
     *     3.2 1ms and 40MB memory in LeetCode
     * 4.Q&A
     *
     * @param nums
     * @return
     */
    public int pivotIndex(int[] nums) {
        if(nums==null||nums.length==0){
            return -1;
        }
        int left=0,right=0;
        for(int num:nums){
            right+=num;
        }
        right-=nums[0];
        if(right==left){
            return 0;
        }
        for(int i=1,length=nums.length;i<length;i++){
            right-=nums[i];
            left+=nums[i-1];
            if(right==left){
                return i;
            }
        }
        return -1;
    }

}

```

### php实现
```
Solution{

    /**
     * 1.关于复杂度
     *   1.1 时间复杂度为 O(n)
     *   1.2 空间负责度为 O(1)
     * 2.我的解题思路
     *   2.1 循环遍历数组将所有数加到 right 变量中
     *   2.2 先用首元素减掉 right 变量，然后跟 left 变量对比
     *   2.3 循环遍历数组，不断减掉 right 变量以及加上 left 变量，对比返回
     * 3.提交记录
     *   3.1 力扣中耗时60ms,消耗16MB内存
     *   3.2 leetcode中耗时52ms,消耗15.8MB内存
     * 4.Q&A
     *
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 circulate array first fill all num to variable right
     *     2.2 subtract right with first num and compare with current variable left
     *     2.3 circulate array,subtract variable right and increase variable left and compare
     * 3.About submit record
     *     3.1 60ms and 16MB memory in LeetCode China
     *     3.2 52ms and 15.8MB memory in LeetCode
     * 4.Q&A
     *
     * @param nums
     * @return
     */
    function pivotIndex($nums) {
        if(!isset($nums) || count($nums) == 0){
            return -1;
        }
        $left = 0;
        $right = array_sum($nums);
        $right -= $nums[0];
        if($left == $right){
            return 0;
        }
        for($index = 1, $len = count($nums); $index < $len; $index++){
            $right -= $nums[$index];
            $left += $nums[$index - 1];
            if($right == $left){
                return $index;
            }
        }
        return -1;
    }

}
```
<br />
如果你有更好的想法或者疑问，可以到 [我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution) 提出issue，我会及时处理
你也可以关注 [我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution) 获得其他题目解题思路


