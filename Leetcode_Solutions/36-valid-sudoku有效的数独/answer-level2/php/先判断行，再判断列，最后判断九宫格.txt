### 解题思路


### 代码

```php
class Solution {

    /**
     * @param String[][] $board
     * @return Boolean
     */
    function isValidSudoku($board) {
        foreach($board as $key => $value){
            foreach($value as $k => $v){
                if($v == '.'){
                    unset($value[$k]);
                }
            }
            $newArr[] = $value;
            if(count($value) != count(array_unique($value))){
                return false;
            }
        }
       
        for($i = 0; $i < count($newArr); $i++){
            for($j = 0;$j < 9;$j++){
                if($newArr[$j][$i]){
                    $verticalArr[$i][] = $newArr[$j][$i];
                }
            }
            if(count($verticalArr[$i]) != count(array_unique($verticalArr[$i]))){
                return false;
            }
        }
        
        foreach($board as $key => $value){
            foreach ($value as $k => $v){
                $first = intval($key / 3) * 3;
                $second = intval($k / 3) + $first;
                if($v != '.'){
                    if(in_array($v,$lastArr[$second])){
                        return false;
                    }
                    $lastArr[$second][] = $v;
                }
            }
        }
       
       return true;
    }
}
```