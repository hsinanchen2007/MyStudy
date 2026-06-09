### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer
     */
    function minIncrementForUnique($A) {
        $count = count($A);
        sort($A);
        $result = [];
        $op = 0;
        for($i=0;$i<$count;$i++){
            if(isset($result[$A[$i]]) && $A[$i]<=($A[$i-1]+1)){
                $op += ($A[$i-1]+1-$A[$i]);
                $A[$i] = $A[$i-1]+1;
            }
            $result[$A[$i]] = true; 
        }
        return $op;
    }
}
```