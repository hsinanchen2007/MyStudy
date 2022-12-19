### 解题思路


### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int len = (int)Math.pow(10,n)-1;
        int[] arr = new int[len];
        for(int i=1; i<=len; i++) {
            arr[i-1] = i;
        }
        return arr;
    }
}
```