### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int len = (new Double(Math.pow(10, n))).intValue() - 1;
        int[] res = new int[len];
        for(int i = 0; i < len;i++){
            res[i] = i + 1;
        }
        return res;
    }
}
```