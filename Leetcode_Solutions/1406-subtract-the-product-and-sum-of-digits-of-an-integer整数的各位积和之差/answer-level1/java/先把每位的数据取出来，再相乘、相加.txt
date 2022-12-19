### 解题思路
先把每位的数据取出来，再相乘、相加

### 代码

```java
import java.util.*;

class Solution {
    public int subtractProductAndSum(int n) {
        List<Integer> list = getEach(n);//取出n在每位上的数字，放到list中
        Optional<Integer> sum = list.stream().reduce((i, j) -> i + j);//求和
        Optional<Integer> multiply = list.stream().reduce((i, j) -> i * j);//乘积
        return multiply.get() - sum.get();//返回结果
    }

    /**
     * 取出n在每位上的数字，放到list中
     */
    private List<Integer> getEach(int n) {
        List<Integer> list = new ArrayList<>();
        while (n > 0) {
            list.add(n % 10);
            n /= 10;
        }
        return list;
    }
}
```