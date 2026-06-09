![image.png](https://pic.leetcode-cn.com/21347703c8df8532fd5bd938a7ac4fee46c659ba44e9c70d14c4f05100d8acb6-image.png)
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function pivotIndex($nums) {
        if (empty($nums)) {
            return -1;
        }
        $count = count($nums);
        $lNum = 0; // 左边合
        $num = 0; // 总数
        # 求合
        for ($i=0;$i<$count;$i++) {
            $num += $nums[$i];
        }
        # 做判断
        for ($i=0;$i<$count;$i++) {
            # 左边等于右边则返回
            if ($lNum == ($num - $lNum - $nums[$i])) {
                return $i;
            }
            # 将左边加起来
            $lNum += $nums[$i];
        }
        return -1;
    }
}
```
