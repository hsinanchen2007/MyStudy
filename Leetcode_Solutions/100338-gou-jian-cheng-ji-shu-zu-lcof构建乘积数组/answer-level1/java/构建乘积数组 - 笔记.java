### 解题思路
采用对称遍历的方式

### 代码

```java
class Solution {

    /**
    * 采用对称遍历的方式
    **/ 
    public int[] constructArr(int[] a) {
        int len = a.length;
        int[] result = new int[len];
        // 将所有初始化为 1
        for (int i = 0; i < len; i++) {
            result[i] = 1;
        }
        int left = 1;
        int right = 1;
        // 从左到右遍历
        for (int i = 0; i < len; i++) {
            result[i] = left;
            left = a[i] * left;  // 给left一个个加上去
        }
        // 从右到左遍历
        for (int i = len - 1; i >= 0; i--) {
            result[i] *= right;  // 因为假设是在最后，那最右边的初始确实是1
            right *= a[i];  // 给right一个个加上去
        }
        return  result;
    }
}
```