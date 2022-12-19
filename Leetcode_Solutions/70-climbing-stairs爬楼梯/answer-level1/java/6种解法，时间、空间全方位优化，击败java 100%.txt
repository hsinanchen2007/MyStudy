### 解法一(公式法)
- [参考此大神](https://leetcode-cn.com/problems/climbing-stairs/solution/hua-jie-suan-fa-70-pa-lou-ti-by-guanpengchn/)的解法一，不过个人认为这种解法并没有什么卵用。
### 解法二(普通递归)
#### 分析
- 分析问题，发现和斐波那契数列差不多，于是很快可以用递归写出来，但显然性能不好，因为有很多重复的计算，提交结果显示超时
#### 代码
```java
    public static int climbStairs(int n) {
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        //递归调用，没啥好说的
        return climbStairs1(n - 1) + climbStairs1(n -2 ) ;
    }
```
### 解法三(时间优化---自底向上)
#### 分析 
- 当我们仔细分析解法二可以发现有很多的重复计算，比如计算`5`，会转为计算`4`和`3`，而计算`4`时一定会计算`3`，所以这里`3`就重复计算了，如果这个数字再大些，比如计算`100`，那么重复计算的就更多了。
#### 解决方案
- 我们能不能有一个东西把计算结果保存起来呢，比如计算`5`，把`3`计算的结果保存起来，下次直接取，这样方便多了，显然，这个保存的容器就是数组了，因为它最简单。
#### 代码
```java
    public static int climbStairs(int n) {
        //用数组来保存每次计算的结果(也可以不是n+1,下面相应的变下就行 )
        int[] sum = new int[n + 1];
        sum[1] = 1;
        if(n == 1){
            return sum[1];
        }
        sum[2] = 2;
        if(n == 2){
            return sum[2];
        }
        //比如n为5，分别计算4，3...1
        for (int i = 3; i <= n; i++) {
            sum[i] = sum[i - 1] + sum[i-2];
        }
        return sum[n];
    }
```
#### 实例分析
- 比如我们计算`5`，它会先计算`3`，然后计算`4`，然后计算`5`，每次计算结果都保存在数组中
### 解法四(时间优化---自顶向下)
#### 分析
- 依旧用一个数组来保存每次的计算结果
#### 代码
```java
    public int climbStairs(int n) {
        //用数组来保存结果
        int[] sum = new int[n + 1];
        
        return climbStairs_(n,sum);
    }
    
    private int climbStairs_(int n,int[] sum){
        sum[1] = 1;
        if(n == 1){
            return sum[1];
        }
        sum[2] = 2;
        if(n == 2){
            return sum[2];
        }
        if(sum[n] == 0){
            sum[n] = climbStairs_(n - 1,sum) + climbStairs_(n - 2,sum);
        }
        return sum[n];
    }
```
### 解法五(空间优化一)
#### 分析
- 上面我们用数组保存每次计算的结果，比如计算`5`，如果是自底向上，可以发现当计算到`3`和`4`时，`1`、`2`已经不需要的，但它依旧占用着空间，随着计算值的增大，数组占用空间大小也变大，那我们能不能避免这种情况呢。
#### 解决方案
- 我们可以用3个变量记录每次计算的值
#### 代码
```java
    public static int climbStairs(int n) {
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        int x = 1,y = 2,sum = 0;
        for(int i = 3,i <= n;i ++>){
            sum = x + y;
            x = y;
            y = sum;
        }
        return sum;
    }
```
### 解法六(空间优化二)
#### 分析
- 上面我们用`3`个变量，这里其实也可以优化到`2`个变量
#### 代码
```java
    public static int climbStairs(int n) {
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        int x = 1,sum = 2;
        for(int i = 3;i <= n; i ++){
            sum = x + sum;
            x = sum - x;
        }
        return sum;
    }
```

