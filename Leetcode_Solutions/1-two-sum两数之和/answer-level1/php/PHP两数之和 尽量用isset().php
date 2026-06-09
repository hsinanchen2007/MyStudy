```
class Solution {

/*
题目

    给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
    你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
示例
    给定 nums = [2, 7, 11, 15], target = 9
    因为 nums[0] + nums[1] = 2 + 7 = 9
    所以返回 [0, 1]

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/two-sum
      著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
    方法一 <暴力法>
    时间复杂度O(n^2)
      对于数组每个元素都要再向后遍历一遍来找到符合要求的 目标元素。
      执行用时 :1736 ms, 在所有 PHP 提交中击败了38.67%的用户
      内存消耗 :15.8 MB, 在所有 PHP 提交中击败了44.21%的用户
*/
  function twoSum1($nums, $target)
  {
    $len = count($nums);//数组长度
    for($i=0; $i<$len; $i++) {
        for($j=$i+1; $j<$len; $j++) {
            if($nums[$j] == $target - $nums[$i]){
               return [$i,$j];//找到了
            }
        }
    }
  }


  /*
    方法二
       时间复杂度O(n)
             利用反转函数array_flip()。同时结合isset()来判断一个值是否在数组中。
             但是这个方法的弊端，也就是事先直接给了哈希，还需要判断是否是当前值，不能两个加数是同一个元素
       执行时间20ms,   在所有 PHP 提交中击败了92.34%的用户
       内存消耗16.2MB, 在所有 PHP 提交中击败了5.03%的用户
  */

    function twoSum2($nums, $target) {
        $renums= array_flip($nums);//反转  多申请了一个数组
        foreach ($nums as $k=>$v) {
            $re = $target - $v;//得到另一个值
            //如果 这个值存在的话，而且不是当前的键对应的，那么就找到一个
            if(isset($renums[$re]) && $renums[$re] != $k ){
                return [$k,$renums[$re]];//确定另一个值是否存在
            }
        }
    }
/*
    方法三
        HashMap 法：
            主要还是PHP的数组太强大啦，直接去查找对应的值的key
            去构建一个对应值=>键的 哈希数组
            至于数组循环的话，用for或者foreach。都行,不过foreach好点
            然后利用isset来进行判断，它是语言结构，比array_key_exists()要快
       思路：
            1. 哈希                  利用$found 来做 值=>键 的哈希
            2. 另一个差值           : 利用目标和$targer 循环减去 数组中每一个$v
            3. 判断是否存在这样的差值：存在就返回 两个加数的位置。
       时间复杂度O(n)
       空间复杂度O(n)
       执行用时 :16 ms, 在所有 PHP 提交中击败了92.34%的用户
       内存消耗 :15.8 MB, 在所有 PHP 提交中击败了29.94%的用户

*/
    function twoSum3($nums, $target) {
        $found = [];
        foreach ($nums as $k => $v) {
            $re = $target - $v;//获得另一个差值
            // if(array_key_exists($re,$found)) {
            if(isset($found[$re])) {
                return [$found[$re], $k];//返回两个位置
            }
            $found[$v] = $k;//构建 以值对应键的 哈希
        }

    }




}

```
