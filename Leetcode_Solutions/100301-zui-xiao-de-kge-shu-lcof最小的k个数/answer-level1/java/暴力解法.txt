### 解题思路
先将数组进行排列，后用循环
代码如下

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
           Arrays.sort(arr);
            int[] a = new int[k];
            for(int i=0;i<k;i++) {
            	a[i] = arr[i];
            }
            return a;
	    }   
}
```