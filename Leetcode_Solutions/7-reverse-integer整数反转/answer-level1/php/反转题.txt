### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        if($x<0){
            $i=(string)$x;
            
            $i=strrev(substr($i,1));
            $i=(int)$i;
            if($i>2147483648){
                $i=0;
            }
            else{
            $i=(string)$i;
            $i='-'.$i;
            }

        }
       else{
           
        $i=(string)$x;
        $i=strrev($i);
        $i=(int)$i;
       if($i>2147483647){
           $i=0;
       }
       }
        return $i;
    }
}
```