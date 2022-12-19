```java
class Solution {

    public int findNumbers(int[] nums) {
        return (int)Arrays.stream(nums).filter(x -> (int)(Math.log10(x) + 1) % 2 == 0).count();
    }

}
```
