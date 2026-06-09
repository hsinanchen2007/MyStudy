```java
class Solution {
    public int[] printNumbers(int n) {
        int  sum = (int)Math.pow(10,n);
        int[] num = new int[sum-1];
        for(int i=0;i<sum-1;i++){
            num[i] = i+1;
        }
        return num;
    }
}
```
