二分查找一定要细心,仔细琢磨每一步查找的比较
```
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer
     */
    function search($nums, $target) {
        $count = count($nums);
        if ($count == 0) {
            return -1;
        }
        if ($count == 1) {
            return $nums[0] == $target ? 0 : -1;
        }
        $row = $this->getRow($nums, 0, $count - 1);
        # 等于零代表数组是一个正序数组
        if ($row == 0) {
            return $this->findIndex($nums, 0, $count-1, $target);
        } elseif ($nums[0] > $target) { # 如果第一个值大于目标值 代表目标值在旋转值后面
            return $this->findIndex($nums, $row, $count-1, $target);
        } else { # 从0开始查找
            return $this->findIndex($nums, 0, $row, $target);
        }
    }

    # 查找旋转值下标
    function getRow($nums, $l, $r){
        if ($nums[$l] < $nums[$r]) {
            return 0;
        }
        while ($l<=$r) {
            $mid = floor(($l+$r) / 2);
            if ($nums[$mid] > $nums[$mid +1]) {
                return $mid + 1;
            } else {
                if ($nums[$mid] < $nums[$l]) {
                    $r = $mid - 1;
                } else{
                    $l = $mid + 1;
                }
            }
        }
    }
    # 查找目标值
    function findIndex($nums, $l, $r, $t) {
        while ($l<=$r) {
            $mid = $l + ( ($r - $l) >> 1 );
            if ($nums[$mid] == $t) {
                return $mid;
            }
            if ($nums[$mid] > $t) {
                $r = $mid - 1;
            } elseif ($nums[$mid] < $t) {
                $l = $mid + 1;
            }
        }
        return -1;
    }
}
```
