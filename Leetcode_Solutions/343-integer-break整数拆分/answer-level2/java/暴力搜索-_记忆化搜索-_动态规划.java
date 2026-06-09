## 题目描述：
> **给定一个正整数`n`，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。**

>**示例 1**:
输入: `2`
输出: `1`
解释: `2 = 1 + 1, 1 × 1 = 1`。
>**示例 2**:
输入: `10`
输出: `36`
解释: `10 = 3 + 3 + 4, 3 × 3 × 4 = 36`。
说明: 你可以假设 `n` 不小于 `2` 且不大于 `58`。

## 思路：
### 1. 暴力搜索
对于给定的一个整数`n`，穷举它的每一种分解情况，然后对所有情况，求最大值。
并且我们知道，`n`可以拆成如下情况：
![图1 整数分解](https://pic.leetcode-cn.com/9f416325c155daf990f88e305c09ee167000954510265d334d0d4ae53243dfb6.png)
<center>**图1 整数n分解**</center>
通过上图，我们很容易得到一个递归表达式：
$$F(n) = max \{i * F(n - i), \ F(n)\}，i = 1，2，... ，n - 1$$

上述表达式是表明`n - i`需要继续分解的情况，但如果`n - i`比`F(n - i)`要大，显然就不用再继续分解了。故我们还需要比较`i * (n - i)`与`i * F(n - i)`的大小关系。所以完整的表达式应该为：
$$F(n) = max \{ i * F(n - i),\  i * (n - i),\  F(n) \} , i = 1, 2, ... , n - 1$$
基于此，就不难得到如下代码：
```java
// 暴力解法
public int integerBreak(int n) {
    if (n == 2) {
        return 1;
    }
    int res = -1;
    for (int i = 1; i <= n - 1; i++) {
        res = Math.max(res, Math.max(i * (n - i), i * integerBreak1(n - i)));
    }
    return res;
}
```
### 2. 记忆化搜索（备忘录）
对于**暴力搜索**，通过图1不难得出该方法的时间复杂度为指数级别，显然不能满足题目要求。那么如此耗时的原因也是因为在递归的过程中计算了很多**重复值**。例如，图1中$F(n-2)$和$F(n-3)$至少重复计算了两次，并且在后面会有更多次重复运算，而这部分重复运算完全是没有必要的，如果我们每次求完一个$F(i)$，都将其保存起来，下次再求的时候直接读取保存的值就行了，这显然会节省大量时间。既然有这个想法，那么相应的代码应该也不难实现，我们只要用一个数组存放每次的$F(i)$，记为`memory`，这个数组我们一般称之为**备忘录数组**，具体实现如下：
```java
// 记忆化搜索-自顶向下
int[] memory;
public int integerBreak(int n) {
    memory = new int[n + 1];
    return integerBreakHelper(n);
}
public int integerBreakHelper(int n) {
    if (n == 2) {
        return 1;
    }
    // memory的初始值为0，如果它不为0，说明已经计算过了，直接返回即可
    if (memory[n] != 0) {
        return memory[n];
    }
    int res = -1;
    for (int i = 1; i <= n - 1; i++) {
        res = Math.max(res, Math.max(i * integerBreakHelper(n - i), i * (n - i)));
    }
    // 将每次计算的结果保存到备忘录数组中
    memory[n] = res;
    return res;
}
```
> 通过上述代码我们可以看出，记忆化搜索是将目标$F(n)$不断转化为求$F(n-1)$,$F(n - 2)$,...,$F(2)$,$F(1)$，过程中将计算过的值存起来，从图1的递归树中看出来这是一个从上到下的过程，一般将之称为`自顶向下`。

### 3. 动态规划
其实，方法2已经满足的题目的要求。但是对于这样的一个`递归`代码，我们更习惯转化为`递推`，将`自顶向下`的思路转换为`自底向上`，这也是记忆化搜索和DP之间的区别所在。
代码如下：
```java
// 动态规划
public int integerBreak3(int n) {
    memory[2] = 1;
    for (int i = 3; i <= n; i++) {
        for ( int j = 1; j <= i - 1; j++) {
            memory[i] = Math.max(memory[i], Math.max(j * memory[i - j], j * (i - j)));
        }
    }
    return memory[n];
}
```