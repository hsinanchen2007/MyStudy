一开始愣是做成了算数，第二眼做成了找规律，最后还是认真思考一个动态规划吧
1、看到“最佳状态”，不就是默认正常每步都为true，那么就看最后是停留在谁那里，不是Alice则为false
```
// 92ms  33.7mb
var divisorGame0 = function(N) {
    return N%2 === 0;
}
```
2、第二次觉得改多列几个试试看，结果发现false、true相互交换；然后代码同上
3、后来觉得这好歹是个动态规划题，还是认真思考一下，按照题述写代码如下
（果然要快一些）
```
// 60ms 34.4mb
var divisorGame = function(N){
    if(N === 1) return false
    if(N === 2) return true
    // 先默认全部为false
    let dp = new Array(N+1).fill(false)
    dp[2] = true // 第二已知为true
    for(let i = 3; i <= N; i++){
        for(let j = 1; j < i; j++){
            /* 判定为true的条件是：
             找到一个约数 且查看减去改约数后，dp[i-j] 为false 那么叠加该次，为true
            */
            // 其实j可以为1,那么正常情况下由该规律推断，i-1前一个一定为!divisorGame(i)，这也是为什么会形成规律的原因
            if(i%j === 0 && !dp[i-j]){
                dp[i] = true
                break
            }
        }
    }
    return dp[N]
}
```

