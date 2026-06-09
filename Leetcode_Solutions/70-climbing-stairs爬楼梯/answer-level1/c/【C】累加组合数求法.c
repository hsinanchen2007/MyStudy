### 解题思路
没有观察到斐波那契规律，但是想到累加组合数的规律。为了防止溢出，改良了组合数求法。
执行用时也是0还不错吧。

### 代码
参考：[组合数](https://baike.baidu.com/item/%E7%BB%84%E5%90%88%E6%95%B0/2153250?fr=aladdin)
图1
![图1](https://pic.leetcode-cn.com/7e8635ddbb89b0169a8bb7f4a1af0f0c23a02a206581a428b76a9acebf844799-image.png)


图2
![图2](https://pic.leetcode-cn.com/91ec0610e84d7f90d215bb1063999e6bf2518c1a323abc39488f9557a25744e9-image.png)

```c
// 求"组合数"
int C(int n, int m) {
    unsigned long ans = 1;
    // 利用组合数的性质，将m取小
    m = m>=n-m ? m : n-m;
    
    // 这个循环计算分子
    // 为了防止结果ans溢出，引入d用于计数，使得每两次ans除以2
    // >>= 是右移位运算，右移1位相当于整除2
    // 要先*i后除2，因为连乘两个i才能必然保证整除2
    for(int i=m+1, d=1; i<=n; ++i, ++d){
        ans *= i;
        ans >>= d%2==0 ? 1 : 0;
    }

    // 这个循环用上步得到的分子依次除掉分母的每一项
    // 为了还原上一个循环的除2影响，每两次ans乘回2
    // <<= 是左移位运算，左移1位相当于乘2
    // 要先乘2后除j，也是为了保证整除
    for(int j=1, d=1; j<=n-m; ++j, ++d){
        ans <<= d%2==0 ? 1 : 0;
        ans /= j;
    }
    return ans;
}

int climbStairs(int n){
    // count表示可能的结果个数
    // 观察题目所求可以发现规律，假设一开始全部都是一步1阶
    // 则n为奇数时初始化为1（全部一步1阶只有一种情况）
    // n为偶数时初始化为2（全部一步1阶1种+全部一步2阶1种）
    unsigned long count = n&1 ? 1 : 2;

    // one表示一步1阶的次数，two表示一步2阶的次数
    // 因为一开始假设全部一步1阶，现在每次把其中两个一步1阶合并成一个一步2阶，然后计算他们的组合数
    // 累加他们的组合数
    for(int one=n, two=0; --one>++two;)
        count += C(one, two);
    return count;
}
```