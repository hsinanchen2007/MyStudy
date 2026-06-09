### 解题思路
动态规划

### 代码

```java
public int deleteAndEarn(int[] nums) {
    int[] cnt = new int[10001];
    int max = 0;
    for (int n : nums) {
        cnt[n]++;
        max = Math.max(max, n);
    }
    int[] ydp = new int[max + 1];
    int[] ndp = new int[max + 1];
    for (int i = 1; i <= max; i++) {
        if (cnt[i] == 0) {// 当前没值,可以任意选择要或者不要上一个值
            ydp[i] = ndp[i] = Math.max(ydp[i - 1], ndp[i - 1]);
        } else {
            ydp[i] = ndp[i - 1] + cnt[i] * i;// 要当前值,那肯定不能要上一个值
            ndp[i] = Math.max(ydp[i - 1], ndp[i - 1]);// 不要当前值,可以任意选择要或者不要上一个值
        }
    }
    return Math.max(ydp[max], ndp[max]);
}
```