### 解题思路
动态规划，类似青蛙跳台阶。

### 代码

```php
class Solution {

    /**
     * @param Integer $num
     * @return Integer
     */
    function translateNum($num) {
        $num = strval($num);
        $length = strlen($num);
        $dp[0]=1;
        $dp[1]=1;

        for($i=2;$i<=$length;$i++){
            //注意特殊情况，当前2个数>25的时候，只能逐个翻译，当倒数第2个数是0的时候，也是逐个翻译。
            if(substr($num,$i-2,2)>25 || (substr($num,$i-2,1)=='0')){
                $dp[$i] = $dp[$i-1];
            }else{
                $dp[$i] = $dp[$i-1]+$dp[$i-2];
            }
        }
        return $dp[$length];
    }
}
```