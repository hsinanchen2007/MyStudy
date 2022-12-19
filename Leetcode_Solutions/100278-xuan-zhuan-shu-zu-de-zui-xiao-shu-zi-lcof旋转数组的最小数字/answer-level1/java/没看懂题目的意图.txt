### 解题思路
这个旋转有什么用，难道就是为了取最小值吗，不是为了查看最小移动次数

### 代码

```java
class Solution {
    public int minArray(int[] numbers) {
        Arrays.sort(numbers);
        return numbers[0];
    }
}
```