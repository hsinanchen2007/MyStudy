### 解题思路
1、能分成三部分的话必然被3整除，计算出sum/3的结果，记为A；
2、采用双指针法，头指针右移直到和为A时停止，所求的和记为headPart；尾指针左移直到和为A时停止，所求的和记为tailPart；
3、求出头、尾指针中间的元素的和，所求的和记为middlePart，判断headPart,middlePart,tailPart是否相等。
![image.png](https://pic.leetcode-cn.com/2a32ba90a0f5d8b28d0a84f53325f995ee2048a75bf3be649f1afb4c5ca03ad0-image.png)

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {

		// 能分成三部分的话必然被3整除
		int sum = 0;
		int avgPart = 0;
		for (int i = 0; i < A.length; i++) {
			sum = sum + A[i];
		}		
		if (sum % 3 != 0) return false;
		avgPart = sum / 3;

		// 双指针法
		int head = 0;
		int tail = A.length - 1;
		int headPart = 0, middlePart = 0, tailPart = 0;
		
		//头部分
		headPart = headPart + A[head];
		while (headPart != avgPart && head + 1 < tail) {
			head++;
			headPart = headPart + A[head];
		}
		
		//尾部分
		tailPart = tailPart + A[tail];
		while (tailPart != avgPart && head + 1 < tail) {
			tail--;
			tailPart = tailPart + A[tail];
		}
		
		//中间部分
		for(int k=head+1;k<tail;k++) {
			middlePart = middlePart + A[k];
		}
		
		if(middlePart==avgPart && head +1 <tail) return true;

		return false;
	
    }
}
```