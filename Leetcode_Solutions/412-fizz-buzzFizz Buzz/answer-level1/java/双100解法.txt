### 解题思路
针对当前条件的最高效解法，但通用性不好。

### 代码

```java
class Solution {
        public List<String> fizzBuzz(int n) {
        List<String> result = new ArrayList<>(n);
        String a = "Fizz";
        String b = "Buzz";
        String ab = "FizzBuzz";
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) result.add(ab);
            else if (i % 3 == 0) result.add(a);
            else if (i % 5 == 0) result.add(b);
            else result.add(String.valueOf(i));
        }
        return result;
    }
}
```