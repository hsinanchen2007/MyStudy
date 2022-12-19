## 有两种解法BFS及DP解法
> 最近参加了期算法训练营， 老师布置这道题目， 所以就过来做了一下， 一看题， 就蒙了， 所以过来看一些题解， 发现也很蒙， 在助教帮助下还算攻克了这道题目， 并附比较好理解题解链接，供大家参考， 并整理了一下DP方程。
[参考链接博客](https://www.cnblogs.com/grandyang/p/10360655.html)

* BFS解法 （具体思路参考链接）
```javascript
    /**
 * @param {number} target
 * @return {number}
 */
var racecar = function(target) {
    let queue = [[0, 1]];
    let visited = new Set(['0,1']);
    let res = 0;

    while(queue.length) {
        let tmp = [];
        for (let i = 0; i < queue.length; i ++) {
            let [posi, speed] = queue[i];
            if (posi == target) return res;
            
            // A 加速 
            let newP = posi + speed, newS = speed * 2;
            addQueue(newP, newS, tmp);
            
            // R 开始变换方向
            newP  = posi, newS = speed > 0 ? -1 : 1;
            addQueue(newP, newS, tmp);
        }
       
        res ++;
        queue= tmp;
    }

    return -1;
    
    function addQueue(posi, speed, tmp) {
        let key = `${posi},${speed}`;
        if (!visited.has(key) && posi > 0 && posi < 2 * target) {
            visited.add(key);
            tmp.push([posi, speed]);
        }
    }
};
```

* DP
  * a. 重复子问题
    * 状态
      * 1. 到达位置i前
        * 正方向加速：
          * j 正方向加速位置(也可以说加速到距离)（1<= j < i）
          *  cnt1 正方向加速次数 j = 2^cnt1 - 1
        * 反方向加速：
          * k 反方向加速位置 (0 <= k < j)  
          * cnt2 反方向加速次数 k = 2^cnt2 - 1
        * 公式 
          * dp[i] = 正方向加速指令cnt1 + R(1) + 反方向加速指令cnt2 + R(1) + dp(i - (j - k))
          * dp[i] = cnt1 + 1 + cnt2 + 1 + dp[i - (j - k)]
        * 迭代每次正向加速到的位置j进行反向加速k
            ```
                for(j = 1, cnt1 = 1; j < i; j = (1 << ++ctn1) - 1)) 
                    for(k = 0, cnt2 = 0; i < j; k = (1 < ++ctn2) - 1)
                        dp[i] = min(dp[i], cnt1 + 1 + cnt2 + 1 + dp[i - (j - k)])
            ```
      * 2. 到达位置之后及刚到i
        * j === i ? ctn1 : cnt1 + 1 + dp[j - i]
      * 3. 总结   
        ```
            for(j = 1, cnt1 = 1; j < i; j = (1 << ++ctn1) - 1)) 
                for(k = 0, cnt2 = 0; i < j; k = (1 << ++ctn2) - 1)
                    dp[i] = min(dp[i], cnt1 + 1 + cnt2 + 1 + dp[i - (j - k)])

            dp[i] = min(dp[i], i === j ? ctn1 : ctn1 + 1 + dp[j - i])
        ```
  * b. 定义状态数组
    * dp[i] i 位置的最短指令长度
  * c. dp方程
    ```
        for(j = 1, cnt1 = 1; j < i; j = (1 << ++ctn1) - 1)) 
            for(k = 0, cnt2 = 0; i < j; k = (1 << ++ctn2) - 1)
                dp[i] = min(dp[i], cnt1 + 1 + cnt2 + 1 + dp[i - (j - k)])

        dp[i] = min(dp[i], i === j ? ctn1 : ctn1 + 1 + dp[j - i])
    ```

* DP 代码部分
```javascript
/**
 * @param {number} target
 * @return {number}
 */
var racecar = function(target) {
    let dp = [];
    for(let i = 1; i <= target; i++) {
        dp[i] = Number.MAX_VALUE;
        let j = 1, cnt1 = 1;
        for (; j < i; j = (1 << ++cnt1) - 1) {
            for (let k = 0, cnt2 = 0; k < j; k = (1 << ++cnt2) - 1) {
                dp[i] = Math.min(dp[i], cnt1 + 1 + cnt2 + 1 + dp[i - (j - k)]);
            }
        }

        dp[i] = Math.min(dp[i], cnt1 + (i == j ? 0 : 1 + dp[j - i]))
    }

    return dp[target];
};
```
