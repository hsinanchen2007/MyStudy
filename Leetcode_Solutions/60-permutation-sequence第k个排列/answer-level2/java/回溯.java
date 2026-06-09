核心公式：当前位置字符 = ((k - 1) % n!) / (n - 1)!
    由于排列是按顺序的，那么第k个排列是可以计算出来的，比如:n=3时。在所有3！= 6个排列中，第一个字符是按照（3-1）！个一组排列的，也就是123,132（（3-1）！）。n=4也一样1234,1243,1324,1342,1423,1432（（4-1）！）。
    那么就可以根据这个规律设计核心公式，前提是在程序设计上需要一个基本字符串。比如当n=3，k=3时第一个字符所在位置为2，是针对123这个字符串来说的，在把2提出后，源字符串应该改写为13.根据这两点不断递归得到结果
```
/**生成基本字符串
	 * @param n
	 * @param k
	 * @return
	 */
	public static String getPermutation(int n, int k) {
		StringBuffer baseStr = new StringBuffer();
		StringBuffer str = new StringBuffer();
		
		for (int i = 1; i <= n; i++) baseStr.append(i);
		
		if(k > factorial(n)) return "";
		
		return doCount(n, k - 1, baseStr, str).toString();
    }
	
	/**根据公式生成字符串
	 * @param n
	 * @param k
	 * @param baseStr
	 * @param str
	 * @return
	 */
	public static StringBuffer doCount(int n, int k, StringBuffer baseStr, StringBuffer str) {
		
		if(n == 1) return str.append(baseStr);
		
		Integer fac = factorial(n - 1);
		int index = k / fac;//获取当前位置的字符
		str.append(baseStr.charAt(index));
		baseStr.deleteCharAt(index);
		return doCount(n - 1, k % fac, baseStr, str);
	}
	
	/**阶乘计算公式
	 * @param n
	 * @return
	 */
	public static Integer factorial(int n){
		if(n <= 0) return 0;
		int fac = 1;
		for (int i = 1; i <= n; i++) {
			fac *= i;
		}
		return fac;
	}
```



