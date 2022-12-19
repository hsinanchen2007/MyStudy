1. 关于复杂度
    1.1 时间复杂度为O(n!)
    1.2 空间负责度为O(1)
2. 我的解题思路
    2.1 这个解法基于滑动窗口
    2.2 定义两个指针，分别是窗口的左边界以及右边界
    2.3 循环遍历数组知道右边界到达数组的右边界
        2.3.1 将右边界元素加到temp中
        2.3.2 对比用temp减去左边界的元素，移动左边界
        2.3.2 对比并更新result
<br />
### java实现
```
/**
 * Problem
 *     209.Minimum Size Subarray Sum
 *     https://leetcode.com/problems/minimum-size-subarray-sum/
 *     https://leetcode-cn.com/problems/minimum-size-subarray-sum/
 * Grade of difficulty
 *     Medium
 * Related topics
 * @author cartoon
 * @version 1.0
 */
class Solution {

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n!)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 this solution is base on slide window
     *     2.2 define two pointer which are window's left border and right border
     *     2.3 circulate until right border reach array length
     *         2.3.1 add right element to temp
     *         2.3.2 compare and subtract temp with left border element and move left border
     *         2.3.3 compare and update result
     * 3.About submit record
     *     3.1 3ms and 40.5MB memory in LeetCode China
     *     3.2 1ms and 36.8MB memory in LeetCode
     * 4.Q&A
     *
     * @param s
     * @param nums
     * @return
     */
    public int minSubArrayLen(int s, int[] nums) {
        int res=Integer.MAX_VALUE,l=0,r=0,length=nums.length,temp=0;
        while(r<length){
            temp+=nums[r];
            while(l<=r&&temp>=s){
                temp-=nums[l];
                res=Math.min(r-l+1,res);
                l++;
            }
            r++;
        }
        if(res==Integer.MAX_VALUE){
            return 0;
        }
        else{
            return res;
        }
    }
}

```

<br />
#### php实现
```
class Solution{

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n!)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 this solution is base on slide window
     *     2.2 define two pointer which are window's left border and right border
     *     2.3 circulate until right border reach array length
     *         2.3.1 add right element to temp
     *         2.3.2 compare and subtract temp with left border element and move left border
     *         2.3.3 compare and update result
     * 3.About submit record
     *     3.1 3ms and 40.5MB memory in LeetCode China
     *     3.2 1ms and 36.8MB memory in LeetCode
     * 4.Q&A
     *
     * @param s
     * @param nums
     * @return
     */
    function minSubArrayLen($s, $nums) {
        $res = 2147483648;
        $l = 0;
        $r = 0;
        $length = count($nums);
        $temp = 0;
        while ($r < $length){
            $temp += $nums[$r];
            while ($l <= $r && $temp >= $s){
                $temp -= $nums[$l];
                $res = $r - $l + 1 > $res ? $res : $r - $l + 1;
                $l++;
            }
            $r++;
        }
        return $res == 2147483648 ? 0 : $res;
    }
}
```

如果你有更好的想法或者疑问，可以到[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)提出issue，我会及时处理
你也可以关注[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)获得其他题目解题思路