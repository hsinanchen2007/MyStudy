### 解题思路

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int number = (int)Math.pow(10,n);
        int[] results = new int[number-1];
        for(int i=0;i<number-1;i++){
            results[i] = i+1;
        }
        return results;
    }
}
```