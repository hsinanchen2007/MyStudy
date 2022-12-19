### 解题思路
运用数组键名唯一特性：array_flip。1.将字符串分割为数组：str_split。2.将数组元素与键名互换：array_flip。3.比较互换前后是否有差值：count()，来判断是否有重复。

### 代码

```php
class Solution {

    /**
     * @param String $astr
     * @return Boolean
     */
    function isUnique($astr) {
        $astrArr = str_split($astr,1);
        $astrCount = count($astrArr);
        $astrCountFlip = count(array_flip($astrArr));
        if($astrCount >= 100 || $astrCount <= 0) print 'input out of limit:0~100.';
        if($astrCount != $astrCountFlip) return false;
        return true;
    }
}
```