### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $coins
     * @param Integer $amount
     * @return Integer
     */
    function coinChange($coins, $amount) {
        if(empty($coins) || empty($amount)){
            return 0;
        }
        $dp=[];
        $dp[0] = 0;
        for ($i = 1; $i <= $amount;$i++) {
            $dp[$i] = $amount+1;//不可能存在的情况
        }
        for($i=1;$i<=$amount;$i++){
            for($j=0;$j<count($coins);$j++){
                if($coins[$j]<=$i){
                    $dp[$i]=min($dp[$i]?$dp[$i]:0,$dp[$i-$coins[$j]]+1);
                }
            }
        }
        //print_r($dp);
        
        return $dp[$amount]>$amount?-1:$dp[$amount];
    }
}
```