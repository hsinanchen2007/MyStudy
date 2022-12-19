### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $prices
     * @return Integer
     */
    /*function maxProfit($prices) {
        //贪心和动态规划
        if(empty($prices)){
            return 0;
        }
        //贪心只加正数
        //$min=$prices[0];
        $res=0;
        for($i=0;$i<count($prices);$i++){
            $money=$prices[$i+1]-$prices[$i];
            if($money>0){
                $res+=$money;
            }
        }
        return $res;
    }*/
    //动态规划
    function maxProfit($prices) {
        //贪心和动态规划
        if(empty($prices)){
            return 0;
        }
        //贪心只加正数
        //$min=$prices[0];
        $res=0;
        $dp=[];
        $dp[0][0] = 0;
        $dp[0][1] = -$prices[0];
        $count=count($prices);
        for($i=1;$i<$count;$i++){
            $dp[$i][0]=max($dp[$i-1][0],$dp[$i-1][1]+$prices[$i]);//无股票
            $dp[$i][1]=max($dp[$i-1][1],$dp[$i-1][0]-$prices[$i]);//无股票
           

        }
        return $dp[$count-1][0];
    }

}
```