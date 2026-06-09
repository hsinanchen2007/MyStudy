### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        Arrays.sort(arr);
        int[] min = new int[k];
        System.arraycopy(arr, 0, min, 0, k);
        return min;
    }
}
```