个人喜欢 左右互动，有的喜欢上下互动
个人喜欢吧，heihei
```
public int peakIndexInMountainArray(int[] A) {
	int left = 0;// 左边界
	int right = A.length - 1;// 右边界
	int middle = (left + right) / 2;

	for (int i = 0; i < A.length; i++) {
		//刚好最大的值就是middle下标对应的值
		if (A[middle] > A[middle - 1] && A[middle] > A[middle + 1]) {
			break;//跳出循环
		}
			
		//middle比一边大，则比另一边小
		if (A[middle] > (A[middle + 1])) {// 中间的数比right的大,right移到middle
			right = middle;
		} else if (A[middle] > (A[middle - 1])) {//中间的数比left的大,left移到middle
			left = middle;
		}
			
		//再进行对middle 取值，如果middle 等于left 或者 right，其实只能等于left，因为向下取整
		//如3，4取3   3，5取4
		middle = (right + left) / 2;
		if (middle == left) {
			break;//跳出循环
		}
	}
	return middle;//返回下标
}
```
