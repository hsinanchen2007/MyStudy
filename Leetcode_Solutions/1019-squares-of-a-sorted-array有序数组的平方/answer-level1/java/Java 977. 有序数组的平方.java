### 解题思路
1. 先定义一个数组`resultArr`用于保存最终返回结果；
2. 遍历数组`A`，然后将其各元素的平方赋给`resultArr`数组；
3. 利用`Arrays`的`sort()`方法`resultArr`数组进行排序；
4. 返回最终结果数组；

### 代码

```java
class Solution {
    public int[] sortedSquares(int[] A) {
        int[] resultArr = new int[A.length];
		for (int i = 0; i < A.length; i++) {
			resultArr[i] = A[i] * A[i];
		}
		Arrays.sort(resultArr);
		return resultArr;
    }
}
```