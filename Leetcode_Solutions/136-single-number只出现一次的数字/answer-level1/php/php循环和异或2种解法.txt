思路：第一种就是利用一遍循环，第二种是利用异或运算（原理请看官方题解）
第一种：
```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function singleNumber($nums) {
        $arr=[];

        foreach($nums as $item){
            if(isset($arr[$item])){
                unset($arr[$item]);
            }else{
                $arr[$item]=$item;
            }
        }

        foreach($arr as $item)
            return $item;
    }
}
```
第二种：
```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function singleNumber($nums) {
        $ret=0;
        foreach($nums as $item){
            $ret^=$item;
        }

        return $ret;
    }
}
```

