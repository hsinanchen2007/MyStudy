
1. 关于复杂度
  1.1 时间复杂度为O(n)
  1.2 空间负责度为O(1)
 2. 我的解题思路
    2.1 利用两个缓存变量存储1的个数
    2.2 遍历数组
    2.2.1 如果当前元素为0，对比result以及temp的值，将temp置0
    2.2.2 如果当前元素为1，temp自增
    2.3 返回temp以及result的较大值
<br />
### java实现
```
/**
 * Problem
 *      485.Max Consecutive Ones
 * Grade of difficulty
 *      Easy
 * Related topics
 * @author cartoon
 * @version 1.0
 */
class Solution{

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(n)
     * 2.how I solve
     *     2.1 use two integer to cache number of 1
     *     2.2 circulate array
     *          2.2.1 if current element is 1,temp++
     *          2.2.2 if current element is 0,compare result to temp and set temp 0
     *     2.3 return the largest of temp and result
     * 3.About submit record
     *     3.1 5ms and 50.7MB memory in LeetCode China
     *     3.2 2ms and 38.2MB memory in LeetCode
     * 4.Q&A
     *      4.1 Q:Why this solution is faster than the another solution with similar structure?
     *          A:I think is about judging condition,cause 1 is main element,so make it to if condition can reduce judge time.
     * @param nums
     * @return
     */
    public int findMaxConsecutiveOnes(int[] nums) {
        if(nums.length==0){
            return 0;
        }
        int result=0;
        int temp=0;
        for(int i:nums){
            if(i==1){
                temp++;
            }
            else{
                result=result<temp?temp:result;
                temp=0;
            }
        }
        return result<temp?temp:result;
    }

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(n)
     * 2.how I solve
     *     2.1 use two integer to cache number of 1
     *     2.2 circulate array
     *          2.2.1 if current element is 0,compare result to temp and set temp 0
     *          2.2.2 if current element is 1,temp++
     *     2.3 return the largest of temp and result
     * 3.About submit record
     *     3.1 8ms and 52.5MB memory in LeetCode China
     *     3.2 3ms and 39.6MB memory in LeetCode
     * 4.Q&A
     * @param nums
     * @return
     */
    public int anotherFindMaxConsecutiveOnes(int[] nums) {
        if(nums.length==0){
            return 0;
        }
        int result=0;
        int temp=0;
        for(int i:nums){
            if(i==0){
                result=temp>result?temp:result;
                temp=0;
                continue;
            }
            temp++;
        }
        result=temp>result?temp:result;
        return result;
    }
}

```
<br/>
### php实现
```
class Solution{

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 use two integer to cache number of 1
     *     2.2 circulate array
     *          2.2.1 if current element is 1,temp++
     *          2.2.2 if current element is 0,compare result to temp and set temp 0
     *     2.3 return the largest of temp and result
     * 3.About submit record
     *     3.1 128ms and 15.9MB memory in LeetCode China
     *     3.2 112ms and 15.8MB memory in LeetCode
     * @param nums
     * @return
     */
    function findMaxConsecutiveOnes($nums) {
        if(count($nums) == 0){
            return 0;
        }
        $res = 0;
        $temp = 0;
        for($index = 0, $len = count($nums); $index < $len; $index++){
            if($nums[$index] == 1){
                $temp++;

            }
            else{
                if($res < $temp){
                    $res = $temp;
                }
                $temp = 0;
            }
        }
        if($res < $temp){
            $res = $temp;
        }
        return $res;
    }
}
```

如果你有更好的想法或者疑问，可以到[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)提出pull request，我会及时处理反馈
你也可以关注[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)获得其他题目解题思路