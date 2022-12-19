### 解题思路
题目要求数据不重复，那么需要了解数据之间的关系，因而首先将数据按照从小到大的顺序排列，计算方式则变成当前的下标的值小于下一个下标的值，如果小于则不需要移位，如果当前大于下一位则需要移位，那么移位次数则为当前值减去下一位的值加1.

### 代码

```php

class Solution {

    /**
     * @param Integer[] $A
     * @return Integer
     */
    function minIncrementForUnique($A) {
        sort($A);
        $count=0;
        for($i=0;$i<count($A)-1;$i++){
            $j=$i+1;
            if ($A[$i]>=$A[$j]){
                    $cha = $A[$i]-$A[$j];
                    $A[$j]+=$cha+1;
                    $count+=$cha+1;
            }
        }
        return $count;
    }
}
```