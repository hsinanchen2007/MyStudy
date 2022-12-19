### [信息]
- - 就地删除给定值的所有元素
    - 我们就必须用 O(1)的额外空间来处理它
- 元素的顺序可以改变
    - 题的条件不是白给的
### [思路]
- [1]foreach循环 / for循环
    - 感觉直接循环，然后unset指定的值就可以鸭。
**阅读官网题解**
- [2]双指针
    - 可以保留两个指针 i 和 j，其中 i 是慢指针，j是快指针。
    - 如果相等  ，那我们递增 j 以跳过该元素。
    - 如果不相等，那我们就赋值nums[j]到指定的nums[i]并同时递增两个索引。
    - 时间复杂度：O(n)，假设数组总共有 n 个元素，i 和 j 至少遍历 2n 步。空间复杂度：O(1)。
- [3]尾部删除
    - 题意：元素的顺序可以改变
    - 在2的基础上 如果双指针 —— 当要删除的元素很少时
    - 如果[1,2,3,5,4]中去除4，我们只需要删除最后一个就行，但是我们按照2的做法，移动的次数会比较多
    - 遍历整个数组
        - 如果遇到相等的元素，那么我们将其尾部的元素复制到当前位置，同时尾部--
            - 同时从尾部移动过来的值也需要进行判断是否相等
        - 如果不相等就直接再继续遍历
            - 这样减少了元素的移动

```
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $val
     * @return Integer
     */
     // foreach 循环
     //执行用时 :12 ms, 在所有 php 提交中击败了47.55%的用户
     //内存消耗 :15.1 MB, 在所有 php 提交中击败了5.60%的用户
    function removeElement(&$nums, $val) {
         foreach ($nums as  $k=>$value) {
             if( $value == $val) {
                 unset($nums[$k]);
             }
         }
         return count($nums);
    }

    //执行用时 :12 ms, 在所有 php 提交中击败了47.55%的用户
    //内存消耗 :14.8 MB, 在所有 php 提交中击败了22.40%的用户
    //快慢指针 ！！！
    function removeElement2(&$nums, $val) {
         $i = 0;//慢指针
         $j = 0;//快指针
         $size = count($nums); //数组大小
         for($j=0; $j<$size; $j++) {
             if($nums[$j] != $val) {//如果不是指定要删除的
                 $nums[$i] = $nums[$j];//就给原地改变
                 $i++;
             }
         }
         return $i;
    }

    //执行用时 :8 ms, 在所有 php 提交中击败了83.22%的用户
    //内存消耗 :14.9 MB, 在所有 php 提交中击败了5.60%的用户
    //改进算法=> 针对场景，对删除元素比例较少的情况
    function removeElement3(&$nums, $val) {
         $j = 0;
         $size = count($nums); //数组大小
         for($j=0; $j<$size; ) {
             if($nums[$j] != $val) {//如果不是指定要删除的
                 $j++;
             }else {//如果需要删除  $nums[$j] == $val
                 $nums[$j] = $nums[$size-1];//把后面的值移动到前面，下次还会判断
                 $size--;//后面的元素不要啦
             }
         }
         return $j;
    }
}

$obj  = new Solution();
$nums = [0,1,2,2,3,0,4,2];
$re   = $obj->removeElement3($nums,2);
var_dump($re);

```
