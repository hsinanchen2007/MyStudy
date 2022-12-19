### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer $N
     * @param Integer[][] $trust
     * @return Integer
     */
    function findJudge($N, $trust) {
        $int = [];
        $out = [];
        for($i = 0;$i<$N;$i++){
            $int[$i] = 0;
            $out[$i] = 0;
        }
        foreach($trust as $k=>$v){
            $int[$v[1]-1]++;
            $out[$v[0]-1]++;
        }
        for($i = 0;$i<$N;$i++){
            if($int[$i] == $N-1 && $out[$i] == 0){
                return $i+1;
            }
        }
        return -1;
    }
}
```