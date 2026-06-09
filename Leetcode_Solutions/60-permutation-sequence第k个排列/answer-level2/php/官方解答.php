### 解题思路
数学知识有些过多

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @param Integer $k
     * @return String
     */
    function getPermutation($n, $k) {
        $arr = [];
        $res = '';
        for($i = 1;$i <= $n;$i++){
            $arr[] = $i;
        }
        while($k > 1){
            $div = $this->do_fac($n-1);
            $curDiv = ceil($k/$div-1);//current digit's division
            $curNum = $arr[$curDiv];//get current digit
            // echo "Cur division: $curDiv >> Cur num: $curNum \n";
            $res .= $curNum;//append the digit to final result
            $n--;
            $k -= $div*$curDiv;//subtrack current combos from remaining combos

            $key = array_search($curNum,$arr);
            unset($arr[$key]);//remove the division number from levels arr

            $arr = array_values($arr);//re-index all values
        }

        // print_r($arr);

        if(!empty($arr)){
            foreach( $arr as $v) {
                $res .=$v;//append all remaining digits to final result
            }
        }
        return $res;
    }

    public function do_fac($n){
        $product = 1;
        while($n>0){
            $product *= $n;
            $n--;
        }
        return $product;
    }

}
```