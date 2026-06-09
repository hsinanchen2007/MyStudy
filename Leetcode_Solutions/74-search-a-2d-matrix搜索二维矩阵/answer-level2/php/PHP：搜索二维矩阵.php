感谢[@rjs](/u/rjs/)在官方评论中的代码，非常nice~

```PHP
class Solution {

    /**
     * @param Integer[][] $matrix
     * @param Integer $target
     * @return Boolean
     */
    function searchMatrix($matrix, $target) {
        if (empty($matrix)) {
            return false;
        }

        // 有多少行
        $rows = count($matrix);
        // 有多少列
        $cols = count($matrix[0]);
        // 设置初始寻找值
        $found = false;

        if ($rows > 0 && $cols > 0) {
            
            // 从第一行最后一个数开始比较
            // 因为最后一个数都是每一行最大的，所以可以用来做搜索的条件
            $row = 0;
            $col = $cols - 1;
            while ($row < $rows && $col >= 0) {
                if ($matrix[$row][$col] == $target) {
                    $found = true;
                    break;
                }else if ($matrix[$row][$col] > $target) {
                    // 如果当前元素大于$target，由题目可知，每一行的最后一个是最大的，所以往前进一列
                    $col--;
                }else if ($matrix[$row][$col] < $target) {
                    // 如果当前元素小于$target，由题可知，每一行的最后一个是最大的，连最大的都小于target，那么就要到下一行去找
                    $row++;
                }
            }

        }

        return $found;
    }
}
```