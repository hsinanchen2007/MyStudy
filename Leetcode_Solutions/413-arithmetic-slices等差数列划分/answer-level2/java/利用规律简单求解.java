# 思路
1. 对于 k 个连续且满足等差条件的元素，每次本段等差数列增加个数 t_count 值，从第 3 个数开始（即第一次出现与上一个差值相同的值时）分别为 1,2,3,...,k-2 。
2. 依照1的规律进行累加最终计数 count 即可。
3. 每次差值变化时，更新记录的当前差值及清空本段等差数列的增加计数。

# 代码
```
public int numberOfArithmeticSlices(int[] A) {
    int len = A.length;
    if (len < 3) {
        return 0;
    }
    int i = 0, diff = A[1] - A[0], t_diff = 0;
    int count = 0, t_count = 0;
    for (i = 2; i < len; i++) {
        t_diff = A[i] - A[i - 1];
        if (diff != t_diff) {
            diff = t_diff;
            t_count = 0;
        } else {
            t_count++;
            count += t_count;
        }
    }
    return count;
}
```

# 总结
- 时间复杂度O(n):遍历一次
- 空间复杂度O(1):未使用额外空间
