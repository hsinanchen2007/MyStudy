### 执行结果
执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :49 MB, 在所有 Java 提交中击败了100.00%的用户
### 解题思路
留坑

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int a=(int)Math.pow(10, n);
		int [] arr= new int[a-1];
		int j=0;
		for(int i=1;i<a;i++) {
			arr[j]=i;
			j++;
		}
		return arr;
    }
}
```