### 解题思路
&emsp;&emsp;官方给出的DP状态和状态转移是
```
    dp[i][k] 表示能否由前面的某一个石头 j 通过跳 k 步到达当前这个石头 i
    dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1]
```
&emsp;&emsp;一开始看到题目的时候想到的是另一种状态和转移方程，于是乎就记录一下
```
    自顶向下
    dp[i][j] 表示能否能由第j块石头跳跃到第i块石头，
    如果j能跳跃到达i，那么两块石头间的距离既是 distance = stones[i] - stones[j]
    且表示必有其中之一
        1.序号为 stones[j] - distance - 1 的第k个石头能跳 distance - 1 的距离到j
        2.序号为 stones[j] - distance 的第k个石头能跳 distance 的距离到j
        3.序号为 stones[j] - distance + 1 的第k个石头能跳 distance + 1 的距离到j
    那怎么表示序号到数组下标的映射呢，那自然是map了，得出状态转移方程（要先判断序号是否存在）
    dp[i][j] = dp[i][j] || dp[j][map[stones[j] - distance - 1]] || 
               dp[j][map[stones[j] - distance - 1]] || dp[j][map[stones[j] - distance + 1]]


    自底向上
    状态同样是 dp[i][j] 表示能否能由第j块石头跳跃到第i块石头，
    如果已知道 dp[i][j] 为true，即j能跳跃到达i，那么j 到 i的跳跃距离是 distance = stones[i] - stones[j]
    因此我们可以推算出本条路线 i 到下个石头的序号
        1. 如果 map(stones[+] + distance - 1) = k 那么 dp[k][i] = true;
        2. 如果 map(stones[+] + distance) = k 那么 dp[k][i] = true;
        3. 如果 map(stones[+] + distance + 1) = k 那么 dp[k][i] = true;
    直到最后一个石头。

```
&emsp;&emsp; 官方是通过遍历距离来计算，我是通过map由距离映射出下标。也说明了dp问题的状态和状态转移只要没问题最终的结果还是一样的。
### 代码

```javascript []
/**
 * @param {number[]} stones
 * @return {boolean}
 */

//自底向上
var canCross = function(stones) {
    //题意得出第二个石子必为1
    if(stones[1] != 1) return false;
    //初始化DP
    let dp = Array.from(new Array(stones.length), ()=> new Array(stones.length).fill(false)),
        map = new Map();
    dp[1][0] = true;
    for(let i = 0; i < stones.length; i++){
        map.set(stones[i], i);
    }
    for(let i = 1; i < stones.length; i++){
        for(let j = i - 1; j >= 0; j--){
            if(i == stones.length - 1 && dp[i][j] == true){
                return true;
            }
            if(dp[i][j] == true){
                let distance = 2 * stones[i] - stones[j];
                map.has(distance + 1) && (dp[map.get(distance + 1)][i] = true);
                map.has(distance) && (dp[map.get(distance)][i] = true);
                map.has(distance - 1) && (dp[map.get(distance - 1)][i] = true);
            }
        }
    }
    return false;
};

//自顶向下
var canCross = function(stones) {
    if(stones[1] != 1) return false;
    let dp = Array.from(new Array(stones.length), ()=> new Array(stones.length).fill(false)),
        map = new Map();
    dp[0][0] = dp[0][1] = true;
    for(let i = 0; i < stones.length; i++){
        map.set(stones[i], i);
    }
    for(let i = 1; i < stones.length; i++){
        for(let j = i - 1; j >= 0; j--){
            let distance = 2 * stones[j] - stones[i];
            dp[j][i] = map.has(distance) && dp[map.get(distance)][j] ||
                         map.has(distance - 1) && dp[map.get(distance - 1)][j] ||
                         map.has(distance + 1) && dp[map.get(distance + 1)][j];
            if(i == dp[0].length - 1 && dp[j][i] == true){
                return true;
            }
        }
    }
    return false;
};

```