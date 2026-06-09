### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int max = 0;
        for(int i=0;i<n;i++){
            max = max * 10 + 9;
        }
        int[]res = new int[max];
        for(int i=0;i<max;i++){
            res[i] = i + 1;
        }
        return res;
    }
}
```