### 解题思路
1. 遍历数组，先将偶数存入数组；
2. 再次遍历数组，将奇数存入数组；
3. 返回结果数组`resultArr`；

### 代码

```java
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int size = A.length;
		int index = 0;
		int[] resultArr = new int[size];
		for (int item : A
		) {
			if (item % 2 == 0) {
				resultArr[index++] = item;
			}
		}

		for (int item : A
		) {
			if (item % 2 != 0) {
				resultArr[index++] = item;
			}
		}

		return resultArr;
    }
}
```