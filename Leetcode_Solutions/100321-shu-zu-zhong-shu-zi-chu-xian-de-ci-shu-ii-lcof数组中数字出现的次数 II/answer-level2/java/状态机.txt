
### 知识储备
- 与运算符 &
	- 两个操作数中位都为1，结果才为1，否则结果为0
- 或运算符 |
	- 两个位只要有一个为1，那么结果就是1，否则就为0
- 非运算符 ~
	- 如果位为0，结果是1，如果位为1，结果是0
- 异或运算符 ^
	- 两个操作数的位中，相同则结果为0，不同则结果为1 
### 图解
![002.png](https://pic.leetcode-cn.com/d538f8fd5e32d534f8380e5401180b2eee4d9bc72143136bb7ab1153a271b5e8-002.png)
### 思路
- 思路懂，我也不知道为什么是这样的
- 第一次向第一个变量暂存
- 第二次与 不一样相加（类似）
- 第三次有一样的抵消掉，暂存数字到第二个变量
- 第四次第一个变量不变新进与第二个变量抵消，第二变量归零

### 代码
```
public static int singleNumber(int[] nums) {
    int ones =0,twos=0;
    for (int num : nums) {
        ones = (ones^num) & ~twos;
        twos = (twos^num) & ~ones;
    }
    return ones;
}
```
