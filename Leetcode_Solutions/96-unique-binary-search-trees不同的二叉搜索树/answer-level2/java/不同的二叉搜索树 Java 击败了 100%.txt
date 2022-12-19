核心是这一行
result += result1 * result2;

memo是用于记录长度为n时有几种排列
for循环更换根节点，两边分割开的数字排列的数目 只跟数字的多少有关

```java
    private int[] memo;

    public int numTrees(int n) {
        if (n < 1) {
            return 0;
        }

        memo = new int[n];

        return numTreesCore(1, n);
    }

    private int numTreesCore(int start, int end) {
        if (start >= end) {
            return 1;
        }

        int result = 0;
        int length1;
        int length2;
        int result1;
        int result2;
        for (int i = start; i <= end; i ++) {
            length1 = i - 1 - start;
            length2 = end - i - 1;

            result1 = length1 >= 0 && memo[length1] > 0 ? memo[length1] : numTreesCore(start, i - 1);
            result2 = length2 >= 0 && memo[length2] > 0 ? memo[length2] : numTreesCore(i + 1, end);

            result += result1 * result2;

            if (length1 >= 0) {
                memo[length1] = result1;
            }

            if (length2 >= 0) {
                memo[length2] = result2;
            }
        }

        return result;
    }
```
