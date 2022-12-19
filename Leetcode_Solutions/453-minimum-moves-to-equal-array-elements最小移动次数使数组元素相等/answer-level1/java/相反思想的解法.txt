1. 关于复杂度
    1.1 时间复杂度为O(n)
    1.2 空间负责度为O(1)
2. 我的解题思路
    2.1 因为题目要求所有数都要增长成一样的，另一方面，它需要的次数与所有元素减少到最小值的次数是相同的
    2.2 统计数组中最小的元素以及数组所有元素的相加值
    2.3 计算减少到最小值所需的次数：sum-min*array.length
<br/>
#### java实现
```
/**
 * Problem
 *      453.Minimum Moves to Equal Array Elements
 *      https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
 *      https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/
 * Grade of difficulty
 *      Easy
 * Related topics
 *      462.Minimum Moves to Equal Array Elements II
 * @author cartoon
 * @version 1.0
 */
class Solution {

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 cause the topic is ask for increase elements to be same,on the contrary,it is asking for each element to reduce 1
     *     2.2 static the min num of array and plus every element of array
     *     2.3 use sum to subtract min*array.length
     * 3.About submit record
     *     3.1 4ms and 49.2MB memory in LeetCode China
     *     3.2 1ms and 40.3MB memory in LeetCode
     * 4.Q&A
     *
     * @param nums
     * @return
     */
    public int minMoves(int[] nums) {
        int min=nums[0];
        int res=0;
        for(int temp:nums){
            res+=temp;
            if(min>temp){
                min=temp;
            }
        }
        return res-min*nums.length;
    }
}
```

<br/>
#### php实现
```
class Solution{

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 cause the topic is ask for increase elements to be same,on the contrary,it is asking for each element to reduce 1
     *     2.2 static the min num of array and plus every element of array
     *     2.3 use sum to subtract min*array.length
     * 3.About submit record
     *     3.1 96ms and 16.1MB memory in LeetCode China
     *     3.2 104ms and 16.5MB memory in LeetCode
     * 4.Q&A
     *
     * @param nums
     * @return
     */
    function minMoves($nums) {
        $min = $nums[0];
        $res = 0;
        for($index = 0, $length = count($nums); $index < $length; $index++){
            $res += $nums[$index];
            if($min > $nums[$index]){
                $min = $nums[$index];
            }
        }
        return $res - $min * count($nums);
    }
}
```

如果你有更好的想法或者疑问，可以到[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)提出issue，我会及时处理
你也可以关注[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)获得其他题目解题思路
