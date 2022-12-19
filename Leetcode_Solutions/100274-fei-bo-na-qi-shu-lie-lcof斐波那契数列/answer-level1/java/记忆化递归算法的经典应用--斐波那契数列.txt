### 写在前面
递归思路：假设第n个数前两个数都算出来，则第n个数可以算出来，即第n个数前两个数之和，然后用同样的思路去处理前两个数

另外，由于该递归运算中会出现大量重复的计算，所以要定义一个存储结构，存储昂贵的函数调用的结果，并在相同的输入再次出现时返回缓存的结果。
效果和明显，测试如下图：
![QQ截图20200214180851.png](https://pic.leetcode-cn.com/a162ce298d81701483dd76236991c6f69592290e1bd396703b45e884b5820d12-QQ%E6%88%AA%E5%9B%BE20200214180851.png)



### 代码

```java
class Solution {
    public int fib(int n) {
        if(n == 0) return 0;
        int[] memorization = new int[n+1]; //用于存储第0~n个数对应的值
		memorization[1] = 1; //第一二个数先定义好，由于第一个数是0，默认即可不用写出
		return Fibonacci(n,memorization);
    }
    public int Fibonacci(int n,int[] memo) {
		if(n < 2 ) //当n等于0或1时，将不再往下递归，直接返回记忆化结果对应的值
			return memo[n];
		if(memo[n] > 0) //当遇到之前计算过的数时，将不再递归往下找，直接用记忆化结果
			return memo[n];
		memo[n] = (Fibonacci(n - 2, memo) + Fibonacci(n - 1, memo)) % 1000000007;
		return memo[n];
    }
}
```