### 解题思路
行数=数组个数,比如3行,123,遍历字符串依次怼进去数组下标,1->2->3->2->1
所以判断数组下标到边界值就改变操作符号(递增或者递减)
怼到字符串没值,就按数组顺序依次输出字符串
### 代码

```php
class Solution {

    /**
     * @param String $s
     * @param Integer $numRows
     * @return String
     */
    function convert($s, $numRows) {
        $now = 0;
        $op = "+";
        for($a = 0;$a < strlen($s);$a++){
            $arr[$now][] = $s[$a];
            if($now == ($numRows - 1)){
                $op = "-";
            }
            if($now == 0){
                $op = "+";
            }

            if($now <= $numRows - 1 && $now >= 0 && $op == "-"){
                $now--;
            }elseif($now >= 0 && $now < $numRows - 1 && $op == "+"){
                $now++;
            }
        }
        $str = "";
        foreach ($arr as $k => $v){
            $str .= implode($v);
        }
        return $str;
    }
}
```