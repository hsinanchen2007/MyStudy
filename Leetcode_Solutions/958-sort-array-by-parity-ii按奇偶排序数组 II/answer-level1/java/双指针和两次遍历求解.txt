### 解题思路
方法一：
开辟一个新数组，第一次遍历原数组将偶数填入偶数位上，第二次遍历数组将奇数填入奇数位上


[个人博客地址](http://47.101.136.180/)

### 代码

```java
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int[] ans = new int[A.length];
        
        int j = 0;
        for (int i = 0; i < A.length; i++) {
        	if (A[i] % 2 == 0) {
        		ans[j] = A[i];
        		j += 2;
        	}
        }
        j=1;
        for (int i = 0; i < A.length; i++) {
        	if (A[i] % 2 == 1) {
        		ans[j] = A[i];
        		j += 2;
        	}
        }
        return ans;
    }
}
```
### 解题思路
方法一：双指针
用指针i遍历奇数位，j遍历偶数位。
遍历奇数位直到不满足要求的位置停下，寻找偶数不满足要求的位置，然后进行交换。

### 代码

```java
class Solution {
	public int[] sortArrayByParityII(int[] A) {
		int j = 0;//j偶数指针，i奇数指针
		
		for (int i = 1; i < A.length; i+=2) {
			if (A[i] % 2 != 1) {
				//寻找不为偶数的小标
				while(j < A.length && A[j] % 2 == 0) {
					j+=2;
				}
				
				//交换
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
		return A;
	}
}
```
