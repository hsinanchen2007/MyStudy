### 解题思路
循环遍历 

### 代码

```java
class Solution {
        public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] resp = new int[nums.length];
        AtomicInteger tmp = new AtomicInteger(0);
        AtomicInteger tmp2 = new AtomicInteger(0);
        AtomicInteger i = new AtomicInteger(0);
        Arrays.stream(nums).forEach(s -> {
            tmp.set(0);
            tmp2.set(s);
            Arrays.stream(nums).filter(s1 -> s1 < tmp2.get()).forEach(s1 -> tmp.getAndIncrement());
            resp[i.get()] = tmp.get();
            i.getAndIncrement();
        });
        return resp;
        }
}
```