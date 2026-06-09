利用lambda表达式
```java
class Solution {
    public String minNumber(int[] nums) {
        return Arrays.stream(nums).mapToObj(String::valueOf).sorted((s1, s2) -> (s1 + s2).compareTo(s2 + s1)).collect(Collectors.joining());
    }
}
```
