### 解题思路
长度少于1000用排序

### 代码

```java
class Solution {
    private static final int EFFECTIVE_LIMIT_LENGTH = 1000;

    public int minIncrementForUnique(int[] a) {
        int move = 0;
        if (a.length < EFFECTIVE_LIMIT_LENGTH) {
            Arrays.sort(a);
            for (int i = 1; i < a.length; i++) {
                if (a[i] <= a[i - 1]) {
                    move += a[i - 1] - a[i] + 1;
                    a[i] = a[i - 1] + 1;
                }
            }
        } else {
            int max = -1, min = 50000;
            int[] count = new int[40001];
            for (int i : a) {
                count[i] ++;
                if (i > max)
                    max = i;
                else if (i < min)
                    min = i;
            }

            for (int i = min; i <= max; i++) {
                if (count[i] > 1) {
                    int step = count[i] - 1;
                    move += step;
                    count[i + 1] += step;
                }
            }
            int rest = count[max + 1] - 1;
            move += (rest + 1) * rest / 2;

        }

        return move;
    }
}
```