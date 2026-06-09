### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] smallestK(int[] arr, int k) {
        Arrays.sort(arr);
        int[] ret = new int[k];
        System.arraycopy(arr,0,ret,0,k);
        return ret;
    }
}
```