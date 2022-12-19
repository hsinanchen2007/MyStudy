### 解题思路
用自带排序方程平均用时30ms，基于官方的解平均用时300ms，耗时差不多是10倍，用意何在？？

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Integer
     */
    //方法一
    // function findKthLargest($nums, $k) {
        // rsort($nums);
        // return $nums[$k-1];

    // }

    //方法二
    public function findKthLargest($nums, $k)
    {
        $len = count($nums);
        $left = 0;
        $right = $len - 1;
        $target = $len - $k;// 转换一下，第 k 大元素的索引是 len - k

        while (true) {
            $index = $this->partition($nums, $left, $right);
            if ($index == $target) {
                return $nums[$index];
            } else {
                if ($index < $target) {
                    $left = $index + 1;
                } else {
                    $right = $index - 1;
                }
            }
        }
    }

    /**
     * 在数组nums的子区间执行partition操作,返回$nums[$left] 排序以后应该在的位置
     * 在遍历过程中保持循环不变量的语义
     * [left +1,j] <nums[left]
     * [j,i]>$nums[left]
     */

    public function partition(&$nums, $left, $right)
    {
        $pivot = $nums[$left];
        $j = $left;
        for ($i = $left + 1; $i <= $right; $i++) {
            if ($nums[$i] < $pivot) { // 小于pivot的元素都被交换到前面
                $j++;
                $this->swap($nums, $j, $i);
            }
        }
        // 在之前的遍历过程中，满足[left +1,j] <nums[left],[j,i]>$nums[left]
        $this->swap($nums, $j, $left);
        // 交换以后 [left, j - 1] < pivot, nums[j] = pivot, [j + 1, right] >= pivot
        return $j;
    }

    public function swap(&$nums, $index1, $index2)
    {
        $tmp = $nums[$index1];
        $nums[$index1] = $nums[$index2];
        $nums[$index2] = $tmp;
    }

}
```