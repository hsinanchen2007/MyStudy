### 解题思路
从数组倒数第二个元素开始倒序，将要移动的元素存入变量中，删除该位置元素，再将变量添加到数组最后

### 代码

```php
class Solution {

    /**
     * @param String[] $s
     * @return NULL
     */
    function reverseString(&$s) {
        for ($i = count($s)-2; $i >= 0; $i--) {
            $tem = $s[$i];
            unset( $s[$i]);
            array_push($s, $tem);
        }
        return $s;
    }
}
```