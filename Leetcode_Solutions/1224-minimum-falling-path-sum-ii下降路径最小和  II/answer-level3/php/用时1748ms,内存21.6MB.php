### 解题思路
确实烧脑，理清思路中最重要一点是，每下降一次可确定前面最短路径，且不影响下一步的下降。
![微信截图_20200328095501.png](https://pic.leetcode-cn.com/49ee4e97f188acc3edbe01c5b779fa2277081baaec4be0bf24d5538dcb361496-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200328095501.png)

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $arr
     * @return Integer
     */
    function minFallingPathSum($arr) {
        // //第一行
        // $sum[0][0] = $arr[0][0];
        // $sum[0][1] = $arr[0][1];
        // $sum[0][2] = $arr[0][2];
        // //下降到第二行
        // $sum[1][0] = $arr[1][0] + min($sum[0][1],$sum[0][2]);
        // $sum[1][1] = $arr[1][1] + min($sum[0][0],$sum[0][2]);
        // $sum[1][2] = $arr[1][2] + min($sum[0][0],$sum[0][1]);
        // //下降到第三行
        // $sum[2][0] = $arr[1][0] + min($sum[1][1],$sum[1][2]);
        // $sum[2][1] = $arr[1][1] + min($sum[1][0],$sum[1][2]);
        // $sum[2][2] = $arr[1][2] + min($sum[1][0],$sum[1][1]);
        // //类推
        // ...
        $arr_len = count($arr);//方阵大小
        for($i=0;$i<$arr_len;$i++){
            if($i==0){
                for($j=0;$j<$arr_len;$j++){
                    $sum[$i][$j] = $arr[$i][$j];
                }
            }else{
                for($j=0;$j<$arr_len;$j++){
                    for($k=0;$k<$arr_len;$k++){
                        if($k!=$j){
                            $j_min = isset($j_min) ? min($j_min,$sum[$i-1][$k]):$sum[$i-1][$k];
                        }
                    }
                    $sum[$i][$j] = $arr[$i][$j] + $j_min;
                    unset($j_min);
                }
            }
        }
        return min($sum[$arr_len-1]);//取下降到最后一行的最小值
    }
}
```