### 解题思路
#### 方法一 直接套公式递归
**思路**：
1.先判断n是否为0和1，是话直接返回n;
2.再判断n是否等于2，使得话返回1；
3.当n大于等于3时，利用递归实现求Tn，即
```java
tribonacci(n)=tribonacci(n-3)+tribonacci(n-2)+tribonacci(n-1);
```

**执行结果**：运算结果没问题，但提交答案时提示执行时间超出限制。可以发现，我们在求Tn的过程中用到了3次递归，所以时间复杂度比较高，需要对递归表达式进行化简。

#### 方法2：化简后的递归表达式
**思路**：
1.先判断n是否为0和1，是话直接返回n;
2.再判断n是否等于2，使得话返回1；
3.如果n是大于等于3小于等于4的话，用方法1求Tn;
4.当n>4时，用下面递归公式求
```java
tribonacci(n)=2*tribonacci(n-1)-tribonacci(n-4)
```
![递归1137.jpg](https://pic.leetcode-cn.com/fb792345cb319b3be04b71169833c74d3facbdcc74501b2c5d71b2b1498d4ab9-%E9%80%92%E5%BD%921137.jpg)

**执行结果**：
通过，执行用时3ms，在Java中击败了15.43%的用户。

### 代码

```java
class Solution {
    public int tribonacci(int n) {
       		if(n<=1 && n>=0) {return n;}
		if(n==2) {return 1;}
		if(n>=3 && n<=4) {
			int h=n-3;
			return tribonacci(h)+tribonacci(h+1)+tribonacci(h+2);
		}
		if(n>4) {
			int h=n-4;
			return 2*tribonacci(n-1)-tribonacci(n-4);
		}
		else {
			return -1;
		}
	} 
}
```