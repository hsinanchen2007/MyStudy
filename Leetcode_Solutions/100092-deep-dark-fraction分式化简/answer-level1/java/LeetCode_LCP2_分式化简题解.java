### 解题思路

$\frac{1}{{a_1}+{\frac{1}{a_2}}} = \frac{a_2}{a_1a_2 + 1}$

因为第0个数字没有被1整除，所以在计算完之后还要交换一次分子分母。

### 代码

```java
class Solution {
    public int[] fraction(int[] cont) {
        int m = 1, n = cont[cont.length - 1], result[] = {m, n};
        for (int i = cont.length - 2; i >= 0; i--) {
            result[0] += result[1] * cont[i];
            swap(result);
        }
        swap(result);
        return result;
    }

    private void swap(int[] result) {
        result[0] += result[1];
        result[1] = result[0] - result[1];
        result[0] = result[0] - result[1];
    }
}
```