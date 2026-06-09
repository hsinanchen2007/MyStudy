### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $val
     * @return Integer
     */
    function removeElement(&$nums, $val) {
        $c = 0;
        foreach($nums as $idx=>$n){
            if($val == $n){
                unset($nums[$idx]);
            }else{
                $c ++;
            }
        }
        return $c;
    }
}
```