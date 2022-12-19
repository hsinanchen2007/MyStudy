`java8`的流特性，不过速度可能没有那么快：

```
    public int singleNumber(int[] nums) {
        Objects.requireNonNull(nums);
        return Arrays.stream(nums).reduce(0, (a, b) -> a ^ b);
    }
```