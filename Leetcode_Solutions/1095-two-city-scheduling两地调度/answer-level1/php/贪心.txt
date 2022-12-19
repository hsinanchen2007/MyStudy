### 解题思路
参考官方
### 代码

```php
class Solution {

    /**
     * @param Integer[][] $costs
     * @return Integer
     */
    function twoCitySchedCost($costs) {
        $new_array = [];
        $sum = 0;
        foreach($costs as $k=>$v){
            $new_array[$k][] = $v[0];
            $new_array[$k][] = $v[1];
          $new_array[$k][] = $v[0]-$v[1];
        }
        $new_column_array = array_column($new_array,'2');
        array_multisort($new_column_array,SORT_ASC,$new_array);
        $length = count($new_array)/2;
        foreach($new_array as $k=>$v){
            if($k<$length){
                $sum += $v[0];
            }else{
                $sum += $v[1];
            }
        }
        return $sum;
    }
}
```