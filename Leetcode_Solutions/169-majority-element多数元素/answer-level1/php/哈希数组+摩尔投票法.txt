# Thinking
[思路]：
- 哈希数组
    + 通过遍历数组中每个元素，用新数组来记录，把元素值做为新数组的键，然后值用于计数；
    + 遍历一次，哈希表的插入是常数时间的，因此时间复杂度为 O(n)；
    + 因为额外使用了数组，所以空间复杂度：O(n)；
- 摩尔投票法(参考别人的题解)
    + 众数的定义是大于n/2（向下取整）;
    + 并且给定的数组总是存在众数，所以题目给的数据，只能由一个众数。
    + 寻找数组中超过一半的数字，这意味着数组中其他数字出现次数的总和都是比不上这个数字出现的次数！
    + 该众数记为 +1 ，把其他数记为 −1 ，将它们全部加起来，和是大于 0 的；
    + 声明两个变量：candidate众数候选者 count当前数字出现的次数
    + 遍历整个数组
        + 第一个元素赋值给candidate ，然后count=1
        + 如果下一个元素，等于 candidate ，那么count+1
        + 如果下一个元素，不等 candidate ，那么count-1
        + 如果count = 0 ,那么下一个元素就重新赋值给candidate ，count=1
        + 最后candidate 就是众数
    + 只有一次循环，因此时间复杂度为 O(n)
    + 只需要两个变量，空间复杂度：O(1)
# Coding
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
     // 哈希数组法
     // 执行用时 :64 ms, 在所有 php 提交中击败了54.07%的用户
     // 内存消耗 :20.1 MB, 在所有 php 提交中击败了94.51%的用户
    function majorityElement($nums) {
        $out  = [];
        $size = count($nums);// 数组大小
        foreach ($nums as $key => $value) {
            if(isset($out[$value])) {
                $out[$value]++;
            }else{
                $out[$value] = 1;
            }
            if($out[$value] > $size/2) {// 题意：次数大于 ⌊ n/2 ⌋ 的元素
                return $value;// 返回众数
            }
        }
    }

    //摩尔投票法
    //执行用时 :56 ms, 在所有 php 提交中击败了87.79%的用户
    //内存消耗 :20.7 MB, 在所有 php 提交中击败了5.49%的用户
    function  majorityElement2($nums) {
        $candiate = $nums[0];
        $count    = 1;
        foreach ($nums as $key => $value) {
           if($count <=0 ){// 如果次数=0
               $candiate = $value;// 移动candiate
               $count    = 1;
           }
           if(!isset($nums[$key+1])) break;// 遍历到最后一个元素
           if($nums[$key+1] == $candiate) {
               $count++;
           }else{
               $count--;
           }
        }
        return $candiate;
    }

}
$obj = new Solution();
$nums= [2,2,1,1,1,2,2];
$res = $obj->majorityElement2($nums);
var_dump($res);

```
