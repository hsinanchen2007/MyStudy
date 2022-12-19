### 解题思路
除去1和2，从序列3开始将数字拆分成数组，统计连续重复数值的长度，与被统计的数一起保存在新的二维数组中，最后将二维数组转换成一位数组得到新的序列

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return String
     */
    function countAndSay($n) {
        if ($n == 1) {
            return '1';
        }
        if ($n == 2) {
            return '11';
        }
        $ns = [1,1];        
        $m = 1;
        for ($m = 1; $m < $n-1; $m++) {
            $i = $j = 0;
            $nss = $tem = array();
            while ($i < count($ns)-1) {
                if (!isset($tem[0][0])) {
                    array_push($tem, [1,$ns[$i]]);
                }
//当前项和下一项相等时只记录重复次数
                if($ns[$i] == $ns[$i+1]){
                    $tem[count($tem)-1][0] = $tem[count($tem)-1][0]+1;
                    $j = $i+1;
                    $i++;
                }else{
//不相等时追加数组，开始新的统计
                    array_push($tem, [1,$ns[$i+1]]);
                    $i++;
                }
            }
            for ($k = 0; $k < count($tem); $k++) {
                for ($l = 0; $l < count($tem[$k]); $l++) {
                    array_push($nss, $tem[$k][$l]);
                }
            }
            $ns = $nss;            
        }
        $n = implode($ns);
        return $n;
    }
}
```