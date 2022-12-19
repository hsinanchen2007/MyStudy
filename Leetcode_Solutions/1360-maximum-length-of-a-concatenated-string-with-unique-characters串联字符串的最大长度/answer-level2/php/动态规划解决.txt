### 解题思路
用动态规划，先解决$arr的前n-1个，然后加上最后一个再处理。
直接上代码。

maxLength2方法为回溯法解决，会超时。

### 代码

```php
class Solution {
    /**
     * @param String[] $arr
     * @return Integer
     */
    function maxLength($arr) {
        list($max_len) = $this->handle($arr);

        return $max_len;
    }

    function handle($arr){
        if(count($arr) == 1){
            if($this->isUnique($arr[0])){
                return array(strlen($arr[0]), $arr);
            }
            return array(0, array());
        }

        $arr_sub = array_slice($arr, 0, count($arr)-1);
        list($max_len, $allarr) = $this->handle($arr_sub);

        $last = $arr[count($arr)-1];

        $newarr = $allarr;
        foreach($allarr as $v){
            if($this->isUnique($v.$last)){
                $newarr[] = $v.$last;
                $max_len = max(strlen($v.$last), $max_len);
            }
        }
        if($this->isUnique($last)){
            $newarr[] = $last;
            $max_len = max(strlen($last), $max_len);
        }
        return array($max_len, $newarr);
    }

    function isUnique($str){
        $arr = str_split($str);
        return count($arr) == count(array_unique($arr));
    }

    /**
     * @param String[] $arr
     * @return Integer
     */
    function maxLength2($arr) {
        $start = 0;
        $stack = array($arr[0]);
        $max = strlen($arr[0]);

        $visted = array('0');

        while(!empty($stack)){
            end($stack);
            list($index, $curr) = each($stack);
            
            for($i=$index+1;$i<count($arr);$i++){
                $str = implode('', $stack);
                if(!in_array(implode(array_keys($stack)).$i, $visted) && $this->isUnique($str.$arr[$i])){
                    $stack[$i] = $arr[$i];
                    $visted[] = implode(array_keys($stack));
                }
            }
            $max = max(strlen(implode('', $stack)), $max);

            array_pop($stack);
            if(empty($stack) && $start < count($arr)-1){
                $stack = array($arr[++$start]);
            }
        }

        return $max;
    }
}


























```