### 解题思路
对于数字 a和b， 直接比较字符串形式的 a+b 和 b+a

### 代码

```java
class Solution {
    public String minNumber(int[] nums) {
        return Arrays.stream(nums)  // 得到 IntStream 流
                .mapToObj(String::valueOf) // 转成 StingStream
                .sorted((a,b)-> (a+b).compareTo(b+a))  // 字符拼接后比较
                .collect(Collectors.joining()); // 将流收集成字符串
    }
}
```