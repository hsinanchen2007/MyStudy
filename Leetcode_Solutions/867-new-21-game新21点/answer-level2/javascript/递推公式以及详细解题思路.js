`f(n)`表示点数为`n`的概率，若不考虑`K`  
`f(n)=f(n-1)/w + f(n-2)/w + ... + f(n-w)/w` `(w项)`  
这个公式怎么得来的呢？
例如: `w`为`5`,`n`为`20`，则`20`只可能由`[15,16,17,18,19]`中的某个数加上`[1,5]`的某个数，**经过`1`步**出来的。  
因此`P(20)`为以下各项概率之和：  
1. `P(19)*N(1)`的概率  
2. `P(18)*N(2)`的概率  
3. `P(17)*N(3)`的概率  
4. `P(16)*N(4)`的概率  
5. `P(15)*N(5)`的概率  
*`N(i)`表示刚好出现`i`的概率*

此时再考虑上`K`，同样以`w=5`，`k=17`，`n=20`为例。
因为`17、18、19`已经大于或等于`k`，因此`20`不可能由`17、18、19`得来，此时
`P(20)`为以下各项概率之和：    

1. ~~`P(19)*N(1)`的概率~~   
2. ~~`P(18)*N(2)`的概率~~  
3. ~~`P(17)*N(3)`的概率~~  
4. `P(16)*N(4)`的概率  
5. `P(15)*N(5)`的概率  
*`N(i)`表示刚好出现`i`的概率*

由此可知：  
`P(n)`最多与其之前的`w`项相关， 并且需要排除掉`n>=k`的项目，因此可以得到与`P(n)`相关的的项的范围为：`[max(0,n-w),min(n-1,k-1)]` ，其小值设为：`left`，大值设为：`right`，则递推公式可以表示为：  
`f(n)=f(min)/w + f(min+1)/w + f(min+2)/w + ... + f(max-1)/w+f(max)/w`   
其结果为最终可能的数的概率和，即：**所有大于等于`K`并且小于等于`N`的数的概率之和**

```js
var new21Game = function(N, K, W) {
    let dp = new Array(N+1).fill(0);
    let sumArr = new Array(N+1).fill(0);
    dp[0]=1;
    for(let n=1;n<=N;n++){
        let left = Math.max(0,n-W);
        let right = Math.min(n-1,K-1);
        let p=0
        for(let i=left;i<=right;i++){
            p+=dp[i]/W;
        }
        dp[n]=p;
        sumArr[n]=sumArr[n-1]+p;
    }
    let result = 0;
    for(let i=K;i<=N;i++){
        result+=dp[i]
    }
    return result;
};
```

考虑到求和还需要遍历一次dp数组，因此不妨再设一个`sumArr`记录前`n`项的概率和，然后考虑`K===0`和`K===1`的情况最终答案为：   

```js
var new21Game = function(N, K, W) {
    if(K===0)return 1;
    if(K===1)return Math.min(N,W)/W;
    let dp = new Array(N+1).fill(0);
    let sumArr = new Array(N+1).fill(0);
    dp[0]=1;
    for(let n=1;n<=N;n++){
        let left = Math.max(0,n-W);
        let right = Math.min(n-1,K-1);
        let p=(sumArr[right]-sumArr[left]+dp[left])/W
        dp[n]=p;
        sumArr[n]=sumArr[n-1]+p;
    }
    return sumArr[N]-sumArr[K-1];
};
```

时间复杂度为：`O(n)`  
空间复杂度为：`O(2n)`