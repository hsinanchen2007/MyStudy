### 解题思路
模拟先把最大的值翻到最前面，再翻转到对应位置，迭代A.length-1次可以完成。

![图片.png](https://pic.leetcode-cn.com/2cb0fba733e1cfff34f39ecce218ff38edb44ba828b76929915ece25c0c73cc6-%E5%9B%BE%E7%89%87.png)

### 代码

```java
class Solution {
    public List<Integer> pancakeSort(int[] A) {
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < A.length - 1; i++) {
            int maxIdx = 0;
            int max = A[0];
            for (int j = 1; j < A.length - i; j++) {
                if (A[j] > max) {
                    max = A[j];
                    maxIdx = j;
                }
            }

            if (maxIdx == A.length - 1 - i) continue;
            if (maxIdx != 0) {
                rollover(A, maxIdx);
                result.add(maxIdx + 1);
            }
            rollover(A, A.length - 1 - i);
            result.add(A.length - i);
        }

        return result;
    }

    private void rollover(int[] A, int n) {
        for (int j = 0; j < (n + 1) / 2; j++) {
            int t = A[j];
            A[j] = A[n - j];
            A[n - j] = t;
        }
    }
}
```