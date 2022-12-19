1. 关于复杂度
  1.1 时间复杂度为O(n)
  1.2 空间负责度为O(n)
2. 我的解题思路
  2.1 这个算法基于桶排序
  2.2 统计得到数组中最大最小值
  2.3 根据数组长度新建桶，每个桶都含有一段范围的数
  2.4 放入所有元素到桶中
  2.5 根据非空桶的最大最小值，对比并更新结果

<br />
#### java代码实现
```
/**
 * Problem
 *     164.Maximum Gap
 *     https://leetcode.com/problems/maximum-gap/
 *     https://leetcode-cn.com/problems/maximum-gap/
 * Grade of difficulty
 *     Hard
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
     *     2.1 this solution is base on bucket sort
     *     2.2 statistics the min and max value from array
     *     2.3 form buckets which is depend on nums.length,finally each bucket which both have a range of num
     *     2.4 put all element to bucket
     *     2.5 compare and set result depend on all not empty bucket
     * 3.About submit record
     *     3.1 3ms and 37.4MB memory in LeetCode China
     *     3.2 2ms and 36.9MB memory in LeetCode
     * 4.Q&A
     *
     * @param nums
     * @return
     */
    public int maximumGap(int[] nums) {
        if (nums == null||nums.length < 2){
            return 0;
        }
        int length=nums.length;
        int min=Integer.MAX_VALUE;
        int max=Integer.MIN_VALUE;
        for(int num:nums){
            min=num<min?num:min;
            max=num>max?num:max;
        }
        if (max == min){
            return 0;
        }
        boolean[] flag=new boolean[length+1];
        int[] left=new int[length+1];
        int[] right=new int[length+1];
        int index;
        for (int i=0;i<length; i++) {
            index=getIndex(nums[i],length,min,max);
            left[index]=flag[index]?Math.min(left[index],nums[i]):nums[i];
            right[index]=flag[index]?Math.max(right[index],nums[i]):nums[i];
            flag[index]=true;
        }
        int res=0;
        int pre=right[0];
        for (int i=1;i<=length;i++) {
            if(flag[i]){
                res=Math.max(res,left[i]-pre);
                pre=right[i];
            }
        }
        return res;
    }

    public int getIndex(long num,long length,long min,long max) {
        return (int)((num - min) * length / (max - min));
    }
}
```

<br/>
#### php代码实现
```
class Solution{

    /**
     * 1. 关于复杂度
     *   1.1 时间复杂度为O(n)
     *   1.2 空间负责度为O(n)
     * 2. 我的解题思路
     *   2.1 这个算法基于桶排序
     *   2.2 统计得到数组中最大最小值
     *   2.3 根据数组长度新建桶，每个桶都含有一段范围的数
     *   2.4 放入所有元素到桶中
     *   2.5 根据非空桶的最大最小值，对比并更新结果
     * 3. 提交记录
     *   3.1 力扣中耗时24ms,消耗16.6MB内存
     *   3.2 leetcode中耗时20ms,消耗16.4MB内存
     * 4. Q&A
     *
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(n)
     * 2.how I solve
     *     2.1 this solution is base on bucket sort
     *     2.2 statistics the min and max value from array
     *     2.3 form buckets which is depend on nums.length,finally each bucket which both have a range of num
     *     2.4 put all element to bucket
     *     2.5 compare and set result depend on all not empty bucket
     * 3.About submit record
     *     3.1 24ms and 16.6MB memory in LeetCode China
     *     3.2 20ms and 16.4MB memory in LeetCode
     * 4.Q&A
     *
     * @param nums
     * @return
     */
    function maximumGap($nums) {
        if($nums == null || count($nums) < 2){
            return 0;
        }
        $length = count($nums);
        $min = 2147483648;
        $max = -2147483648;
        for($index = 0; $index < $length; $index++){
            $min = $nums[$index] < $min ? $nums[$index] : $min;
            $max = $nums[$index] > $max ? $nums[$index] : $max;
        }
        if($max == $min){
            return 0;
        }
        $flag = [];
        $left = [];
        $right = [];
        for($index = 0; $index <= $length; $index++){
            array_push($flag, false);
            array_push($left, 0);
            array_push($right, 0);
        }
        for($index = 0; $index < $length; $index++){
            $tempIndex = $this->getIndex($nums[$index], $length, $min, $max);
            $left[$tempIndex] = $flag[$tempIndex] ?
                ($left[$tempIndex] > $nums[$index] ? $nums[$index] : $left[$tempIndex]):$nums[$index];
            $right[$tempIndex] = $flag[$tempIndex] ?
                ($right[$tempIndex] > $nums[$index] ?  $right[$tempIndex] : $nums[$index]) : $nums[$index];
            $flag[$tempIndex] = true;
        }
        $res = 0;
        $pre = $right[0];
        for($index = 1; $index <= $length; $index++){
            if($flag[$index]){
                $res = $res > $left[$index] - $pre ? $res : $left[$index] - $pre;
                $pre = $right[$index];
            }
        }
        return $res;
    }

    function getIndex($num, $length, $min, $max){
        return ($num - $min) * $length / ($max - $min);
    }
}
```

如果你有更好的想法或者疑问，可以到 [我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution) 提出issue，我会及时处理
你也可以关注 [我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution) 获得其他题目解题思路