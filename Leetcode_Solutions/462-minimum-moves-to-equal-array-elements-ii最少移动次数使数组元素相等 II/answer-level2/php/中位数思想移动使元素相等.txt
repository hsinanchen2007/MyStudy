1. 关于复杂度
    1.1 时间复杂度为O(nlogn/n^2)(因jdk版本与底层选择的排序算法不同而不同)
    1.2 空间负责度为O(1)
2. 我的解题思路
    2.1 这个解法基于中位数实现
    2.2 将数组进行排序，左右指针遍历数组彼此相减逐步靠近中位数

<br />
### java实现
```
/**
 * Problem
 *     462.Minimum Moves to Equal Array Elements II
 *     https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
 * Grade of difficulty
 *     Medium
 * Related topics
 * @author cartoon
 * @version 1.0
 */
class Solution{

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(nlogn)(different with jdk version and underlying algorithm)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 this solution is base on median idea
     *     2.2 first exclude nums.length<2,cause answer is 0 for certain
     *     2.3 sort th array,define two pointer to circulate from head and tail,subtract each other
     * 3.About submit record
     *     3.1 4ms and 37.8MB memory in LeetCode China
     *     3.2 2ms and 37.8MB memory in LeetCode
     * 4.Q&A
     * @param nums
     * @return
     */
    public int minMoves2(int[] nums) {
        if(nums==null||nums.length<2){
            return 0;
        }
        Arrays.sort(nums);
        int i=0,j=nums.length-1,res=0;
        while(i<j){
            res+=nums[j--]-nums[i++];
        }
        return res;
    }
}
```
<br />

### php实现
```
class Solution462{

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(nlogn)(different with jdk version and underlying algorithm)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 this solution is base on median idea
     *     2.2 first exclude nums.length<2,cause answer is 0 for certain
     *     2.3 sort the array,define two pointer to circulate from head and tail,subtract each other
     * 3.About submit record
     *     3.1 32ms and 16.2MB memory in LeetCode China
     *     3.2 28ms and 16.2MB memory in LeetCode
     * 4.Q&A
     * @param nums
     * @return
     */
    function minMoves2($nums) {
        if(empty($nums) || count($nums) < 2){
            return 0;
        }
        sort($nums);
        $i = 0;
        $j = count($nums) - 1;
        $res = 0;
        while($i < $j){
            $res += $nums[$j--] - $nums[$i++];
        }
        return $res;
    }
}
```
如果你有更好的想法或者疑问，可以到[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)提出issue，我会及时处理
你也可以关注[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)获得其他题目解题思路