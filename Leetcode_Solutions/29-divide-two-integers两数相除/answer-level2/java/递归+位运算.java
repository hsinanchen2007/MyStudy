执行用时 : 6 ms, 在Divide Two Integers的Java提交中击败了91.42% 的用户
内存消耗 : 33.6 MB, 在Divide Two Integers的Java提交中击败了76.86% 的用户
```
// 位运算 + 递归实现
	// 思路 : 所有的数字都可以用二进制来表示
	/* 计算过程如下
	 * 100/2 = 2*32 + 2*16 + 2*2;
	 * 32+16+2 = 50
	 * 100/3 = 3*32 + 3*1
	 * 32 + 1 = 33
	*/
	public int divide(int dividend, int divisor) {
		if (dividend == Integer.MIN_VALUE && divisor == -1) {
			return Integer.MAX_VALUE;
		}
		// 全部记录为负数，统一符号，同时避免最大负数转为正数时会溢出的问题
		int positiveDividend = dividend > 0 ? 0 - dividend : dividend;
		int positiveDivisor = divisor > 0 ? 0 - divisor : divisor;
		// 记录位运算左移次数
		int leftTime = 0;
		int result = 0;
		// 记录最小整数右移一位的结果
		int maxRight1 = Integer.MIN_VALUE >> 1;
		if (dividend == 0 || positiveDividend - positiveDivisor > 0) return 0;
		while (positiveDividend - positiveDivisor < 0) {
			// 如果除数小于最小整数右移一位，说明不能再左移了，跳出循环
			if (positiveDivisor < maxRight1 || positiveDividend - (positiveDivisor << 1) > 0) break;
			positiveDivisor = positiveDivisor << 1;
			leftTime ++;
		}
		// 递归
		result = (1 << leftTime) 
				+ divide(positiveDividend - positiveDivisor, divisor > 0 ? 0 - divisor : divisor);
		if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
			result = 0 - result;
		}
		return result;
	}
```