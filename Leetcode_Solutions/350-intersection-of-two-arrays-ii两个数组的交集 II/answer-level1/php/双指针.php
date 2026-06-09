### [THINKING]
- 不能去重，跟349的 两个数组交集I 差不多
- 排序 + 双指针
### [CODING]
```
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[]
     */
    function intersect($nums1, $nums2) {
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
$nums1 = [1,2,2,1];
$nums2 = [2,2];
$res   = $obj->intersect($nums1,$nums2);
var_dump($res);
```
