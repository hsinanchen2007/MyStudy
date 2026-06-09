### 思路
1. 求因子，遍历的之后最大只要到开根号就可以了；
2. 然后用一个`set`来存放遍历过程中的因子，如果发现`set.size() > 4` 就可以结束当前遍历。这是一种优化；
3. 然后遍历完判断`set`的`size`是否等于`4`，等于`4`的话就计算所有因子的和。
4. 直到把数组中所有的数都遍历完为止。

```java
 private int getAns(int n) {
        int end = (int) Math.sqrt(n);
        Set<Integer> set = new HashSet<>();
        for (int i = 1; i <= end; i++) {
            if (n % i == 0) {
                set.add(i);
                set.add(n / i);
                if (set.size() > 4) {
                    return 0;
                }
            }
        }

        if (set.size() != 4) {
            return 0;
        }

        int ans = 0;
        for (Integer num :  set) {
            ans += num;
        }
        return ans;
    }

    public int sumFourDivisors(int[] nums) {
        int ans = 0;
        for (int num : nums) {
            ans += getAns(num);
        }
        return ans;
    }
```

### 复杂度分析
- 时间复杂度: $O(n*sqrt(n))$
- 空间复杂度: $O(1)$，因为set最多存放四个数，因此可以认为是常数量级的。