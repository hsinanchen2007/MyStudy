
![Snip20200229_1.png](https://pic.leetcode-cn.com/fb4737d37c9e1436d8f69d6810c65f398d4d909bc8ba203bac7f16a6d2a8d1d2-Snip20200229_1.png)

### 代码

```java
class Solution {
    public int subarraysWithKDistinct(int[] A, int K) {
        int len;
        if (K == 0 || A == null || (len = A.length) == 0) {
            return 0;
        }

        // 根据题目最后的条件，可以创建缓存数组，比 HashMap 更快.
        int[] cacheArr = new int[len + 1];
        int count = 0;
        int prefix = 0;
        int result = 0;
        for (int left = 0, right = 0; right < len; ++right) {
            // 存储右指针的值到缓存数组中，并加1，如果值等于1，表示第一次存储该值，则将计数 +1.
            if (++cacheArr[A[right]] == 1) {
                ++count;
            }

            // 如果计数大于 K，前缀变为 0，去掉缓存数组中的最左边的一个元素，并将计数 -1.
            if (count > K) {
                prefix = 0;
                --cacheArr[A[left++]];
                --count;
            }

            // 循环处理缓存数组中，最左边的重复元素，去掉多少个，前缀数就加几个，便于后面累加结果.
            while (cacheArr[A[left]] > 1) {
                --cacheArr[A[left++]];
                ++prefix;
            }

            // 如果计数等于 K，说明满足条件，将 prefix数 和本身满足条件的数（1）累加到 result 结果中，
            if (count == K) {
                result += prefix + 1;
            }
        }

        return result;
    }
}
```