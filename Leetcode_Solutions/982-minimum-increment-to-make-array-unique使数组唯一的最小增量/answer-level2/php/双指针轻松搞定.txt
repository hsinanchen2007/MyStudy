### 解题思路
排序后使用双指针

### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer
     */
    function minIncrementForUnique($aNums) {
        // 排序
        sort($aNums);
        $iSlow = 0;
        $iFast = 1;
        $iAction = 0;
        while ($iFast < count($aNums)) {
            // 前值大于等于后值时，后值小于前值出现在给fast指针的值加数时
            if ($aNums[$iSlow] >= $aNums[$iFast]) {
                $iAdd = $aNums[$iSlow]-$aNums[$iFast]+1; // 后值需增加的最小值
                $aNums[$iFast] += $iAdd;
                $iAction += $iAdd;
            }
            $iSlow++;
            $iFast++;
        }

        return $iAction;
    }
}
```