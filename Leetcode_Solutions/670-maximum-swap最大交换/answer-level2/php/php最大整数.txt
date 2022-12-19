### 解题思路
1、将整数转换为字符数据
2、比较i，j,如果j>i,交换，与输入整数进行比较
3、恢复i,j位置，继续比较

### 代码

```php
class Solution {

    /**
     * @param Integer $num
     * @return Integer
     */
    function maximumSwap($num) {
        if ($num < 0) return false;
        if ($num < 10) return $num;

       $maxNum = $num;
       $numStr = str_split(strval($num));
       for($i = 0; $i < count($numStr); $i++){
           for($j = $i + 1; $j < count($numStr); $j++){
               $this->swap($numStr, $i, $j);
               $t = intval(implode("", $numStr));
               if($t > $maxNum){
                   $maxNum = $t;
               }
                $this->swap($numStr, $j, $i);
           }
        }
        return $maxNum;
    }

    function swap(&$nums, $i, $j){
        $tmp = $nums[$i];
        $nums[$i] = $nums[$j];
        $nums[$j] = $tmp;  
    }
}


```