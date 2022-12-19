### [THINKING]
- 哈希法
    - 去重
    - 对某个$nums1数组进行hash，
    - 循环遍历 $nums2
        - 另一个数组$nums2进行判断是否存在相同的值
        - 如果不存在则进行unset
        - 如果存在则跳过
    - 最后返回$nums2
- 排序法+双指针

[函数]
- array_unique ( array $array [, int $sort_flags = SORT_STRING ] ) : array
    - array_unique() 接受 array 作为输入并返回没有重复值的新数组。
    - 键名保留不变
- sort ( array &$array [, int $sort_flags = SORT_REGULAR ] ) : bool
    - 本函数对数组进行排序。当本函数结束时数组单元将被从最低到最高重新安排。
### [CODING]
 ```
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[]
     */
     // 哈希法
    function intersection($nums1, $nums2) {
        // 先去重
        $nums1 = array_unique($nums1);
        $nums2 = array_unique($nums2);
        foreach ($nums1 as $key => $value) {
            $hash[$value] = true;
        }
        // 判断是否存在
        foreach ($nums2 as $key => $value) {
            if(!isset($hash[$value])) {
                unset($nums2[$key]);
            }
        }
        return $nums2;
    }

    // 双指针
    // 执行用时 :16 ms, 在所有 php 提交中击败了64.71%的用户
    // 内存消耗 :15.4 MB, 在所有 php 提交中击败了5.41%的用户
    function intersection2($nums1, $nums2) {
        // 去重
        $nums1 = array_unique($nums1);
        $nums2 = array_unique($nums2);
        // 排序
        sort($nums1);
        sort($nums2);
        // 返回的交集
        $res = [];
        $i = $j = 0;
        // 如果有哪个数组遍历结束，则循环结束
        while($i < count($nums1) && $j < count($nums2)) {
            // 交集放在结果集中
            if($nums1[$i] == $nums2[$j]) {
                $res[] = $nums1[$i];
                ++$i;
                ++$j;
            }elseif($nums1[$i] < $nums2[$j]){
                // 谁小谁移动
                ++$i;
            }else{
                ++$j;
            }
        }
        return $res;
    }

}
$obj   = new Solution();
$nums1 = [4,9,5,10,100];
$nums2 = [9,4,9,8,4];
$res   = $obj->intersection2($nums1,$nums2);
var_dump($res);
```
