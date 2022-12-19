### 解题思路
1、求解出n位最大的整数
2、构造数组，进行赋值

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int number = 1;
        for(int i=0;i<n;i++){
            number = number * 10;
        }
        number--;
        int[] res = new int[number];
        for (int i=0;i<number;i++){
            res[i] = i + 1;
        }
        return res;
    }
}
```