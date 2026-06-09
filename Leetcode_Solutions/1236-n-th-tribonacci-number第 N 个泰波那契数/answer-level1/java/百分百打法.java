### 解题思路
不加记忆的递归会超时，加上数组记忆

### 代码

```java
class Solution {
    int[] mems;

    public int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }

        if (n == 1 || n == 2) {
            return 1;
        }
        mems = new int[n + 1];
        Arrays.fill(mems, -1);
        mems[0] = 0;
        mems[1] = 1;
        mems[2] = 1;
        helpter(n);
        return mems[n];
    }

    private int helpter(int n) {
        if (n == 0 || n == 1 || n == 2) {
            return mems[n];
        }
        if (mems[n] > 0) {
            return mems[n];
        }
        int tmp = helpter(n - 1) + helpter(n - 2) + helpter(n - 3);
        mems[n] = tmp;
        return tmp;
    }
}
```