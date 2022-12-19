### 解题思路
1. 递归开始的条件：末尾指针指向的数字是9；
2. 递归结束的条件：末尾指针指向的数字不是9；
3. 递归的入参：当前最新的数组，及即将处理的指针位置；

### 代码

```php
class Solution {

    /**
     * @param Integer[] $digits
     * @return Integer[]
     */
    function plusOne($digits) {
        $p = count($digits) - 1;
        $arrRes = $this->helper($digits, $p);
        return $arrRes;
    }

    function helper($digits, $p) {
        if($digits[$p] === 9) {
            $digits[$p] = 0;
            if($p > 0) {
                $digits = $this->helper($digits, --$p);
            } else {
                array_unshift($digits, 1);
            }
        } else {
            ++$digits[$p];
        }
        return $digits;
    }
}
```