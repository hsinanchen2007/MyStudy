### 解题思路
此题的关键在于找出返回数组的长度，比如说n=3时，最大值999 = 10*10*10-1；只要找出数组的最大长度，一个for循环就可以打印出来所有的值

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int len = 1;
        for (int i = 0; i < n; i++) {
            len *= 10;
        }
        int[] res = new int[len - 1];
        int index = 0;
        for (int i = 1; i < len; i++) {
            res[index++] = i;
        }
        return res;
    }
}
```