### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] fraction(int[] cont) {
        int[] res = new int[2];
        res[0] = cont[cont.length - 1];
        res[1] = 1;
        for (int i = cont.length - 1; i > 0; i--) {
            int temp = res[0];
            res[0] = cont[i - 1] * res[0] + res[1];
            res[1] = temp;
        }
        return res;
    }
}
```