动态规划：
```
function minimumTotal($triangle) {
    $n = count($triangle);
    $dp[$n-1] = $triangle[$n-1]; // 最底层每个元素到达底部的最小路径
    for($i=$n-2;$i>=0;$i--){ // 自下而上动态规划
        for($j=0;$j<count($triangle[$i]);$j++){
            $dp[$i][$j] = min($dp[$i+1][$j],$dp[$i+1][$j+1]) + $triangle[$i][$j];
        }
    }
    return $dp[0][0]; 
}
```
优化代码：
```
function minimumTotal($triangle) {
    for($i=count($triangle)-2;$i>=0;$i--) // 自下而上动态规划
        for($j=0;$j<count($triangle[$i]);$j++)
            $triangle[$i][$j] = min($triangle[$i+1][$j],$triangle[$i+1][$j+1]) + $triangle[$i][$j];
    return $triangle[0][0]; 
}
```