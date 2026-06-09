

状态设计：
typedef enum {START, DELIMITER("/"), CHAR, DOT, DDOT, END} State;

状态转移图：
![1.png](https://pic.leetcode-cn.com/4c2002d0f3cb81f0c4ea9e8b6ca0d760a8a597fb9c1863c839c0964d25344e0c-1.png)


考虑到 可以从CHAR， DOT， DDOT ， DELIMITER均可到达DELIMITER状态，而DELIMITER可以到达END状态。所以优化一下（在输入字符串中，最后强制加一个"/", 状态转移图：
![2.png](https://pic.leetcode-cn.com/0c1a69c9b8343faefcbc40f8cfe1b299190f56f8ecff2d89403fc52fc4060fd7-2.png)


在验证过程中， 用例 "/…xxx （三个点）”没有考虑到（原程序当做异常返回了），但在Unix下，是合法目录。所以增加 Ddot2转移。问题得以解决。


状态实现：
![3.png](https://pic.leetcode-cn.com/c1dc3aacb8084a798f0f698c0c5c32c5eede90b8878b2b29d291ccb22a593a52-3.png)



使用表格法进行状态机调度，并进一步优化圈复杂度。


![4.png](https://pic.leetcode-cn.com/b4d9805c6e8a3fe7be4de03503eadf34ffa52fa20ce90f02e37579ed76122595-4.png)
