### 解题思路
双重循环比较
有两种情况
1 M在前
2 N在前

```php
class Solution {

    /**
     * @param Integer[] $arr
     * @return Boolean
     */
    function checkIfExist($arr) {
        $len = count($arr);

        for($i=0;$i<$len;$i++){

            for($j=$i+1;$j<$len;$j++){
                if($arr[$i]*2 == $arr[$j] && $i != $j){
                    return true;
                }
                if($arr[$i]/2 == $arr[$j] && $i != $j){
                    return true;
                }
            }

        }
        return false;
    }
}
```