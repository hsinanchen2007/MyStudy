### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if (arr == null || k >= arr.length) {
            return arr;
        }
        Arrays.sort(arr);
        int[] ret = new int[k];
        for (int i = 0; i < k; i++) {
            ret[i] = arr[i];
        }
        return ret;
    }
}
```