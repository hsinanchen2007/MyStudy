（1）计算两个数的差值：第二个数减去第一个数字；
（2）第一个数字加上差值；
（3）第二个数减去差值，即完成两个数的交换。
```
public static int[] swapNumbers(int[] numbers) {
	int sub=numbers[1]-numbers[0];
	numbers[0]=numbers[0]+sub;
	numbers[1]=numbers[1]-sub;
	return numbers;
}
```
