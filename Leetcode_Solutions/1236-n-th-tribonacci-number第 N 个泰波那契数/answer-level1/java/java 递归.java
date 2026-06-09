### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int tribonacci(int n) {
        int[] arr = new int[38];
        arr[0] = 0;arr[1] = arr[2] = 1;
        for(int i = 3;i<=n;i++){
            arr[i] = arr[i-3] + arr[i-2] + arr[i-1];
        }
        return arr[n];
    }
}
```