
思路：
>    nums1 有足够的空间（空间大小大于或等于 m + n） 意思是将最后合并的数列都放在nums1   由于数组有序的。这个题一看到就知道也是用双指针,方向却也有不同;

- 两个个指针从前向后：
    - O(n+m)的时间复杂度。O(m) 的空间复杂度。
    1. 两个都指针分别指向每个数组的开头：
    2. 但是需要额外的空间复杂度来存储 合并后的数组；
    3. 最终的输出数组在nums1中
- 两个指针从后向前：
    1. 两个指针分别指向每个数组的尾部：
    2. 这样不用额外的空间。

```
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer $m  元素个数
     * @param Integer[] $nums2
     * @param Integer $n 元素个数
     * @return NULL
     */
     // 执行用时 :4 ms, 在所有 php 提交中击败了99.34%的用户
     // 内存消耗 :15 MB, 在所有 php 提交中击败了5.56%的用户
     // 思路一 ：两个指针都从前到后，需要额外的数组
    function merge(&$nums1, $m, $nums2, $n) {
           $copy = $nums1; //拷贝一份
           $p1   = $p2 = 0;//两个指针
           $p    = 0;
           //两个 有序整数数组 可能有一方先循环结束
           while (($p1 < $m) && ($p2 < $n)) {
               $nums1[$p++] =  ($copy[$p1] < $nums2[$p2]) ? $copy[$p1++] : $nums2[$p2++];
           }
           //如果 $nums1 先循环结束
           if($p1 >= $m) {
               while ($p2 < $n){
                   $nums1[$p++] = $nums2[$p2++];
               }
           }
            //如果 $nums2 先循环结束
           if($p2 >= $n) {
               while ($p1 < $m){
                   $nums1[$p++] = $copy[$p1++];
               }
           }
              $nums1 = array_splice($nums1, 0, $m+$n);//截取后面多余的
    }


    // 8 ms, 在所有 php 提交中击败了85.53%的用户
    // 14.9 MB, 在所有 php 提交中击败了20.00%的用户
    // 思路二：双指针 从后往前开始。不需要额外的空间
     function merge2(&$nums1, $m, $nums2, $n) {
           //两个指针的下标
           $p1 = $m - 1;
           $p2 = $n - 1;
           $p  = $m + $n - 1;//指向 nums1合并后末尾的位置
           while(($p1 >=0) && ($p2 >=0)) {
               $nums1[$p--] = ($nums1[$p1] < $nums2[$p2]) ? $nums2[$p2--] : $nums1[$p1--];//谁大，把谁放在末尾
           }
            //当然也有可能nums1都很大，已经循环结束，但是nums2还没合并过去
            while ($p1 < 0 && $p2 >= 0) {
                $nums1[$p--] = $nums2[$p2 --];
            }
            $nums1 = array_splice($nums1, 0, $m+$n);//截取后面多余的
     }
}

$obj = new Solution();
$nums1 = [8,10,15,0,0,0,0];
$nums2 = [2,5,6];
$m = 3;
$n = 3;

$obj->merge2($nums1,$m,$nums2,$n);
var_dump($nums1);

```
