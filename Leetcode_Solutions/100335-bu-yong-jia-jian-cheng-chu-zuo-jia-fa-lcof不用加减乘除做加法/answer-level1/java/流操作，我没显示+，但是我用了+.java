### 解题思路
看到源代码，力扣应该会被气死

### 代码

```java
class Solution {
    public int add(int a, int b) {
 return  Stream.of(a,b).reduce(0, Integer::sum);
    }
}
```
上面用到的流的reduce
而 Stream中的Reduce方法的工作是：根据一定的规则将Stream中的元素进行计算后返回一个唯一的值。

```java
    public static int sum(int a, int b) {
        return a + b;
    }
```