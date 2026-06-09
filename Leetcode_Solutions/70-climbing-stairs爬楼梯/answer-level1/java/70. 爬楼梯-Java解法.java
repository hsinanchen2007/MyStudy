```java
/*
 * @lc app=leetcode.cn id=70 lang=java
 *
 * [70] 爬楼梯
 * 解题思路：假设楼梯数为 n，我们有 an 种方法可以爬到楼顶
 * 1. 当 n=1时，a1=1;
 * 2. 当 n=2时，方法有(1+1; 2)，a2=2；
 * 3. 当 n=3时，方法有(1+1+1; 2+1; 1+2)，a3=3；
 * 4. 当 n=4时，方法有(1+1+1+1; 2+1+1; 1+2+1; 1+1+2; 2+2)，a4=5；
 * 5. 我们来总结一下：不妨设a0=1,则a2=a0+a1; a3=a1+a2; a4=a2+a3; ...
 * 6. 爬楼梯模型符合 斐波那契数列，只是在初值设置上有细微的区别
 * 7. 感兴趣的话，可以推一下a5，一定等于 a3+a4=8
 */
```
### 递归实现
```java
// 递归实现，缺点是运行效率慢，n=43时运行就超时了
   public int climbStairs(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
```

### 循环实现
```java
public int climbStairs(int n) {
        if ((n == 1) || (n == 2))
            return n;
        int pre = 1; // 存储前一个数
        int current = 2; // 存储当前数
        for (int i = 3; i < (n + 1); i++) {
            int tmp = current; // 先保留当前数，之和要充作前一个数
            current += pre;
            pre = tmp;
        }
        return current;
}
```