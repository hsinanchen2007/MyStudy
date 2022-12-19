### 解题思路
利用Java的Math包下的pow()方法，创建一个长度为 Math.pow(10,n) - 1 数组
再往数组添加元素。

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int[] res = new int[(int)Math.pow(10,n) - 1];
        for(int i = 0;i < res.length;i++){
            res[i] = i + 1;
        }
        return res;
    }
}
```