1. 关于复杂度
  1.1 时间复杂度为 O(n)
  1.2 空间负责度为 O(1)
2. 我的解题思路
  2.1 将前k个元素加到结果 res 中
  2.2 将 res 的值赋给临时变量 temp
  2.3 对临时变量 temp 进行加当前元素以及减去 i-k 索引下的元素，对比 temp 以及 sum 的大小并交换

<br />
### java实现
```
class Solution{

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 add first k element to sum
     *     2.2 set temp with sum's value
     *     2.3 add temp with remaining element and subtract i-k element,compare temp with sum and change
     * 3.About submit record
     *     3.1 4ms and 40.9MB memory in LeetCode China
     *     3.2 3ms and 41.5MB memory in LeetCode
     * 4.Q&A
     * @param nums
     * @param k
     * @return
     */
    public double findMaxAverage(int[] nums, int k) {
        if(nums==null||nums.length<k){
            return 0;
        }
        int res=0;
        for(int i=0;i<k;i++){
            res+=nums[i];
        }
        int temp=res;
        for(int i=k,length=nums.length;i<length;i++){
            temp+=nums[i]-nums[i-k];
            res=Math.max(temp,res);
        }
        return res*1.0/k;
    }
}
```

<br />
### php实现
```
class Solution{

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 add first k element to sum
     *     2.2 set temp with sum's value
     *     2.3 add temp with remaining element and subtract i-k element,compare temp with sum and change
     * 3.About submit record
     *     3.1 432ms and 19.3MB memory in LeetCode China
     *     3.2 288ms and 19.3MB memory in LeetCode
     * 4.Q&A
     * @param nums
     * @param k
     * @return
     */
    function findMaxAverage($nums, $k) {
        if(!isset($nums) || count($nums) < $k){
            return 0;
        }
        $res = 0;
        for($index = 0; $index < $k; $index++){
            $res += $nums[$index];
        }
        $temp = $res;
        for($index = $k, $len = count($nums); $index < $len; $index++){
            $temp += $nums[$index] - $nums[$index - $k];
            if($temp > $res){
                $res = $temp;
            }
        }
        return number_format($res * 1.0 / $k, 5);
    }
}
```

如果你有更好的想法或者疑问，可以到 [我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution) 提出issue，我会及时处理
你也可以关注 [我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution) 获得其他题目解题思路