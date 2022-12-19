### 解题思路
此处撰写解题思路
本题的思路即为动态规划的思想， 在当前位置获得的最大时长即为max(f(1)...f(n-1))+value,所以根据此公式统计

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function massage($nums) {
        //f(n) = max(f(1)...f(n - 1))
        $arrDp = [];
        foreach ($nums as $key => $num) {
            if (!$arrDp) {
                $arrDp[$key] = $num;
            } else {
                $value = array_pop($arrDp);
                if (!$arrDp) {
                    $arrDp[$key - 1] = $value;
                    $arrDp[$key] = $num;
                } else {
                    $maxValue = max($arrDp);
                    $arrDp[$key - 1] = $value;
                    $arrDp[$key] = $maxValue + $num;
                }
            }
        }
        return $arrDp ? max($arrDp) : 0;
    }
}
```