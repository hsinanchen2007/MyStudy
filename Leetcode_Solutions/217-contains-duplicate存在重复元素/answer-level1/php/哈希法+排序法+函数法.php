# [THINKING]
- 哈希法[常用]
    - 遍历整个数组；
    - 然后对应的值存入哈希表中；
    - 每次判断某个值，在哈希表中是否存在这样的值；
- 排序法
    - 可以使用系统自带的排序函数，通常时间复杂度，如堆排或者快排 O(logn)
    - 排序通常是预处理的很好的办法；
    - 扫描已排序的数组,以查找是否有任何连续的重复元素；
- 函数法
    - 整数数组,想到PHP的去重函数 array_unique()
    - array_unique() 函数移除数组中的重复的值，并返回结果数组。
    - 当几个数组元素的值相等时，只保留第一个元素，其他的元素被删除。
    - 那么我们可以比较去重前的数组长度 和 去重后的数组长度

# [CODING]

```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Boolean
     */
     // 哈希法
     // 执行用时 :40 ms, 在所有 php 提交中击败了93.94%的用户
     // 内存消耗 :21.1 MB, 在所有 php 提交中击败了44.12%的用户
    function containsDuplicate($nums) {
         $map = []; // 哈希表
         foreach ($nums as $key => $value) {
             if(isset($map[$value])){
                 return true;// 如果存在那么就返回有重复的值
             }else{
                 $map[$value] = 1;
             }
         }
         return false;
    }

    // 排序法
    //执行用时 :56 ms, 在所有 php 提交中击败了35.86%的用户
    //内存消耗 :20.4 MB, 在所有 php 提交中击败了94.12%的用户
    function containsDuplicate2($nums) {
        sort($nums); // 升序
        $size = sizeof($nums);
        for($i=0; $i<$size-1;$i++) {
            if($nums[$i] == $nums[$i+1]) return true;
        }
        return false;
    }

    // 函数法
    //执行用时 :40 ms, 在所有 php 提交中击败了93.94%的用户
    //内存消耗 :22.6 MB, 在所有 php 提交中击败了17.65%的用户
    function containsDuplicate3($nums) {
        return sizeof($nums) != sizeof(array_unique($nums));
    }
}

$obj    = new Solution();
$nums   = [1,2,3,1];
$re     = $obj->containsDuplicate3($nums);
var_dump($re);

```
