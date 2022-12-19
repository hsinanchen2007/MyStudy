# 【THINKING】
- 哈希法
    - 声明一个$map 哈希数组
    - 遍历整个数组，然后利用目标值，减轻当前元素，得到另一个值$re
    - 如果$re存在哈希数组中，就返回对应当前位置，和哈希数组中的位置
    - 如果不存在，那么将$re加入哈希数组中，$map[值]=下标
    - 但是转念一想，貌似这个并没有用到有序数组。！！！
    - 时间复杂度O(1)
    - 空间复杂度O(2)
- 双指针
    - 这个方法真的绝！！！
    - 由于数组是有序的，从小到大！！！
    - 初始化：一个指向第一个元素，一个指向最后一个元素
    - 然后求两个指针指向的和，与目标值比较
    - 如果和大于目标值，那么较大的指针向左移动，--
    - 如果和小于目标值，那么教小的指针向右移动，++
    - 时间复杂度：O(n)。每个元素最多被访问一次，共有 n 个元素。
    - 空间复杂度：O(1)。

# 【CODING】

```
class Solution {

    /**
     * @param Integer[] $numbers
     * @param Integer $target
     * @return Integer[]
     */
     // HashMap哈希数组实现
     // 执行用时 :32 ms, 在所有 php 提交中击败了22.78%的用户
     // 内存消耗 :16.4 MB, 在所有 php 提交中击败了93.33%的用户
    function twoSum($numbers, $target) {
        $map = [];
        foreach ($numbers as $k => $v) {
            $re = $target - $v;// 获得另一个差值
            if(isset($map[$re])) {
                return [$map[$re]+1, $k+1];// 返回两个位置，不是下标
            }
            $map[$v] = $k;// 构建 以值对应键的 哈希
        }
    }

    // 双指针
    // 执行用时 :20 ms, 在所有 php 提交中击败了79.75%的用户
    // 内存消耗 :
    function twoSum2($numbers, $target) {
        $size = sizeof($numbers);
        if($size < 2) return [0,0]; // 如果数组中没有两个以上的数字，直接返回
        $left = 0;
        $right= $size-1;
        while($left < $right) {
            $sum = $numbers[$left] + $numbers[$right];
            if($sum == $target) {
                return [++$left,++$right]; // 返回位置
            }elseif($sum > $target) { // 和大
                --$right;
            }else{ // 和小
                ++$left;
            }
        }
        return [0,0];
    }
}

$numbers  = [2, 7, 11, 15];
$target   = 9;
$obj      = new Solution();
$res      = $obj->twoSum2($numbers,$target);
var_dump($res);

```
