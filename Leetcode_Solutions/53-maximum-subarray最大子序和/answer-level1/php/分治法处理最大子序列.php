### 解题思路
算法理解了，但是写的时候细节不行，各种bug。。。真是个菜鸡。。

执行用时 :
92 ms
, 在所有 PHP 提交中击败了
8.37%
的用户
内存消耗 :
16.8 MB
, 在所有 PHP 提交中击败了
5.41%
的用户

真特么的慢。。。

首先将数组利用二分法递归分成左右两个数组。

算出左边数组从中间起的最大和，
算出右边数组从中间起的最大和，
算出他们的和，即穿过中间值的和，
判断这三个哪个最大，并存入maxsum中

最后递归判断出最大值。

### 代码

```php
class Solution
{

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    public $maxsum;

    function maxSubArray($nums)
    {
        if (count($nums) == 1) return $nums[0];
        $this->maxSum($nums);
        return $this->maxsum;
    }

    function maxSum($nums)
    {
        if (count($nums) == 1) return $nums;
        $mid = count($nums) >> 1;
        $left = array_slice($nums, 0, $mid);
        $right = array_slice($nums, $mid);
        $left = $this->maxSum($left);
        $right = $this->maxSum($right);

        $maxLeft = $left[count($left) - 1];
        $leftSum = $left[count($left) - 1];
        for ($i = count($left) - 1; $i - 1 >= 0; $i--) {
            // 每次相加完毕后，找出当前最大值
            $leftSum += $left[$i - 1];
            $maxLeft = max($maxLeft, $leftSum);
        }


        $maxRight = $right[0];
        $rightSum = $right[0];
        for ($i = 0; $i + 1 < count($right); $i++) {
            // 每次相加完毕后，找出当前最大值
            $rightSum += $right[$i + 1];
            $maxRight = max($maxRight, $rightSum);
        }

        $crosssum = $maxLeft + $maxRight;

        // 数组只有单个元素的时候，没有maxsum，所以要进行判断是否存在
        $this->maxsum = isset($this->maxsum) ? max($this->maxsum, max(max($maxLeft, $maxRight), $crosssum)) : max(max($maxLeft, $maxRight), $crosssum);
        return array_merge($left, $right);
    }
}
```