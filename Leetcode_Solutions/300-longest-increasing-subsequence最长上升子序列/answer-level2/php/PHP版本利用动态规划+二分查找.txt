### 解题思路
首先，需要对子序列和子串进行区分；
子序列（subsequence）：并不要求连续。
子串（substring、subarray）：一定是连续的。
1.子序列问题--->动态规划
2.定义一个状态：list[i] 表示长度为 i + 1 的所有最长上升子序列的结尾的最小值
3.对原数列进行遍历，将每位元素二分插入 list中，
如果 list 中元素都比它小，将它插到最后
否则，用它覆盖掉比它大的元素中最小的那个
思想就是让list中存储比较小的元素。这样，list未必是真实的最长上升子序列，但长度是对的。
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function lengthOfLIS($nums) {
        if (count($nums) < 1) {
            return 0;
        }
        $list[0] = $nums[0];
        $end = 0;
        for ($i = 1; $i < count($nums); $i++) {
            if ($list[$end] < $nums[$i]) {
                $end++;
                $list[$end] = $nums[$i];
            } else {
                $left = 0;
                $right = $end;
                while($left < $right) {
                    $mind = ($left + $right) >> 1;
                    if ($list[$mind] < $nums[$i]) {
                        $left = $mind + 1;
                    } else {
                        $right = $mind;
                    }
                }
                $list[$left] = $nums[$i];
            }
        }
        $end++;
        return $end;

    }
}
```