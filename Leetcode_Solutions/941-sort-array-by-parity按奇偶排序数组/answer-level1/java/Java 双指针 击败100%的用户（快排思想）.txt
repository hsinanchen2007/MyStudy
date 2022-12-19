**思路**：双指针
1. i从前往后扫描，A[i]为偶数时一直往后扫，当A[i]为奇数时停止，
2. j从前往后扫描，A[j]为奇数时一直往后扫，当A[j]为偶数时停止，
3. 此时利用temp交换A[i]和A[j]的值，直到指针i和j相遇。

![image.png](https://pic.leetcode-cn.com/7f69621fd76253912985fbcce3a92af24d7483303e04e7be37ace8356a4cf8e3-image.png)

```
public int[] sortArrayByParity(int[] A) {
		int i = 0, j = A.length - 1;
		while(i < j) {
			while(A[i] % 2 == 0 && i < j) i++;
			while(A[j] % 2 == 1 && i < j) j--;
			int temp = A[i];
			A[i++] = A[j];
			A[j--] = temp;
		}
		return A;
	}
```

时间复杂度：O(n)
空间复杂度：O(1)

