```Java []
class Fib{
	/**
	 * 1.动态规划：0,  1,  1,  2,  3,  5,...
	 * i=0		 num sum
	 * i=1			 num sum
	 * i=2				 num sum	
	 * i=3					 num sum
	 * ....       ...
	 * 
	 * 执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
	 * 内存消耗 :33.5 MB, 在所有 Java 提交中击败了51.25%的用户
	 * 
	 */
	public int fib1(int N) {
		int i = 0;
		int sum = 0, num = 1;
		while(i++ < N) {
			sum += num;
			num = sum - num;
		}
		return sum;
	}
	
	/**
	 *2.递归：F(N) = F(N-1) + F(N-2）
	 * 
	 * 执行用时 :14 ms, 在所有 Java 提交中击败了32.70%的用户
	 * 内存消耗 :32.8 MB, 在所有 Java 提交中击败了70.17%的用户
	 */
	public int fib2(int N) {
		if(N == 0) return 0;
		if(N == 1) return 1;
		return fib2(N-1) + fib2(N-2);
	}
}
```
