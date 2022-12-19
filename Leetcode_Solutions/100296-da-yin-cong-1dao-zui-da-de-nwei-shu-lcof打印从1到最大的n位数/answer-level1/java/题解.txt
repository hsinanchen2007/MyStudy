### 解题思路
1、求出最大数
2、赋值

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int len=1;

        for(int i=0;i<n;i++){
            len*=10;
        }
        len=len-1;
        int[] results=new int[len];
        for(int i=1;i<=len;i++){
            results[i-1]=i;
        }
        return results;
    }
}
```