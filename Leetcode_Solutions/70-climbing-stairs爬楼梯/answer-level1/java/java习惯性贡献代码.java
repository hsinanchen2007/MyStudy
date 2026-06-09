## 1、斐波那契数递归

经典题斐波那契数的递归，在这里也是直接优选。每个数字n，第一步可能是1也可能是2，使用递归的出口是n等于1或2. 因为每一步有2个分支，一共n层，时间复杂度是O(2^n)，空间复杂度是O(n).

代码：

```java
public int climbStairs(int n) {
    if (n==2){
        return 2;
    } else if (n==1){
        return 1;
    }
    return climbStairs(n-1) + climbStairs(n-2);
}
```



## 2、记忆化递归

解法1的不足在于有冗余，可以用一个数组来存储计算过的结果，重复计算时直接取值返回。每一步依然是2个分支，但是记忆化的结果省去了一个分支的计算量，时间复杂度O(1^n).

代码：

```java
public int climbStairs(int n) {
    int[] memo = new int [n+1];
    return countSolutions(n,memo);
}
public int countSolutions(int n, int[] memo){
    if (n==2){
        return 2;
    } else if (n==1){
        return 1;
    }
    if (memo [n]>0){
        return memo[n];
    }
    memo[n] = countSolutions(n-1, memo) + countSolutions(n-2, memo);
    return memo [n];
}
```



## 3、动态规划

用动态规划来思考，得到n阶可以由(n-1阶+1)和(n-2阶+2)这2种情况，所以最少已知第1阶和第2阶的方法数，就可以递推到n阶的方法总和。

dp表示方法和，dp[n]=dp[n-1]+dp[n-2].

代码：

```java
public int climbStairs(int n) {
    if (n <=1) return 1;
    int[] dp = new int [n+1];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++){
        dp [i] = dp [i-1] +dp [i-2];
    }
    return dp [n];
}
```

从上面的公式推演：
dp[n]=dp[n-1]+dp[n-2]

dp[n+1]=dp[n]+dp[n-1]

step3=step2+step1;

本质上时间复杂度没有变化，但是减少维护一个数组可以优化空间复杂度。

优化代码：

```java
public int climbStairs(int n) {
    if (n <=1) return 1;
    int first = 1;
    int second = 2;
    int third;
    for (int i = 3; i <= n; i++){
        third = second + first;
        first = second;
        second = third;
    }
    return third;
}
```

