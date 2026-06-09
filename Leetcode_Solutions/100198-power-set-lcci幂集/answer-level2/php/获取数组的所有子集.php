### 解题思路
暴力拆除，后续考虑使用`并查集`实现

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function subsets($nums) {
        $length = count($nums);
        $end = pow(2, $length); // 排列组合公式可得，子集合个数为 2^n 个
        $arrRet = array();
        for ($i = 0; $i < $end; $i ++) {
            $k = $i;
            $arrRet[$i] = array();
            for ($j = 0; $j < $length; $j ++) {
                $flag = $k % 2; // 因为[1,2] 和 [2,1] 是用一个集合，所以只取一个
                if ($flag == 1) {
                    $arrRet[$i][] = $nums[$j];
                }
                $k = intval($k / 2);
            }
        }
        return $arrRet;
    }
}
```