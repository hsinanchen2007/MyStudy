### 解题思路
内存消耗还可以

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int i;
        int[] a = new int[(int)Math.pow(10,n)];
        int[] b = new int[(int)Math.pow(10,n) - 1];
        for(i = 0;i < (int)Math.pow(10,n);i++){
            if(i != 0)
                a[i] = i;
        }
        for(i = 0;i < (int)Math.pow(10,n) - 1;i++){
            b[i] = a[i + 1];
        }
        return b;
    }
}
```