### 解题思路

判断数组最后一位是否是9：
    是：数组最后一位进1，即末位为0；
        判断"最后一位"前面是否还有其他元素：
            有：
                递归判断该位是否为9，以及后续的判断。
            没有：
                在最新数组前面插入1，即在0前插入1。
    不是：数组最后一位直接加1，返回最新数组即可。
### 代码

```php
class Solution {

    /**
     * @param Integer[] $digits
     * @return Integer[]
     */
    public function plusOne($digits) {
        $p = --count($digits);
        $arrRes = $this->checkData($digits, $p);
        return $arrRes;
    }

    /**
     * @param Integer[] $digits
     * @param Integer $p
     * @return Integer[]
     */
    public function checkData($digits, $p) {
        if($digits[$p] === 9) {
            $digits[$p] = 0;
            if($p > 0) {
                $digits = $this->checkData($digits, --$p);
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