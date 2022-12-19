### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer $N
     * @return String
     */
    function baseNeg2($N) {
        if($N == 0){
            return "0";
        }
        $ret = "";
        while($N){
            if($N % 2 == 0){
                $ret = "0".$ret;
                $N = $N / (-2);
            }else{
                $ret = "1".$ret;
                $N = ($N - 1) / (-2);
            }
        }
        return $ret;
    }
}
```