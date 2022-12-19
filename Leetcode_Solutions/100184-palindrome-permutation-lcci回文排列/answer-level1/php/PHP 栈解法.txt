### 解题思路

使用一个辅助栈处理，提前对字符串进行排序。

注意： sort() 函数是对数组进行排序，没有直接对字符串排序的函数。

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function canPermutePalindrome($s) {
        $len = strlen($s);
        if ($len <= 1) {
            return true;
        }
        sort($s);
        $sArr = str_split($s, 1);
        sort($sArr);
        $stack = new SplStack();
        for ($i = 0; $i < $len; ++$i) {
            $char = $sArr[$i];
            if ($stack->count() && $stack->top() == $char) {
                $stack->pop();
            } else {
                $stack->push($char);
            }
        }

        return $stack->count() <= 1;
    }
}
```