### 解题思路
该题无考核点。

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int[] arr = new int[(int)Math.pow(10,n)-1];
        for(int i = 0; i < Math.pow(10,n)-1; i++) {
            arr[i] = i+1;
        }

        return arr;

    }
}
```