执行结果：通过
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :38 MB, 在所有 Java 提交中击败了100.00%的用户

### 解题思路
方法比较笨，欢迎转载(充当反面教材)
主要是根据两个指针分别指向0的时候进行分类讨论(细化讨论几个注意点)

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        if(m == 0)
        	System.arraycopy(B, 0, A, 0, n);
	int pa = m - 1;
	int pb = n - 1;
	int i = A.length-1;
	while(pa >= 0 && pb >= 0) {
	if(pa == 0) {
		if(A[pa] < B[pb]) {
			A[i--] = B[pb--];
		}else {
			A[i--] = A[pa];
			System.arraycopy(B, 0, A, 0, pb+1);
			break;
		}
	}else if(pb == 0) {
		if(A[pa] > B[pb]) {
			A[i--] = A[pa--];
		}else {
			A[i--] = B[pb];
			break;
		}
	}else if(A[pa] > B[pb]) {
		A[i--] = A[pa--];
	}else {
		A[i--] = B[pb--];
		}
	}
    }
}
```