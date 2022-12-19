等差数列求和公式

$$
S_n = a_1 + a_2 + ... + a_n = na_1 + \frac{n(n-1)}{2}d
$$

已知公差d=1，则有
$$
S_n = a_1 + a_2 + ... + a_n = na_1 + \frac{n(n-1)}{2}
$$

已知sn，每次循环时固定的n，直接可得到a1，然后从a1开始以等差1递增n次即可得到一个合法序列。
当 a1 不是整数时，跳过循环；当 sn 不够减时，结束循环。

n 最多循环 √target 次，每次里面的小循环也需要 n 次(也就是 √target 次) ，所以总的时间复杂度是 `O(target)`

```java
private static class SolutionV2020 {
    public int[][] findContinuousSequence(int sn) {
        LinkedList<List<Integer>> listList = new LinkedList<>();
        // n: 等差序列的个数，从2开始往上找
        for (int n = 2; ; n++) {
            // 等差数列求和公式 sn = na1 + dn(n-1)/2，已知公差d=1，则有 sn = na1 + n(n-1)/2，已知sn，每次循环时的n，直接可得到a1
            int na1 = sn - n * (n-1) / 2;
            // 结束循环
            if (na1 <= 0) {
                break;
            }
            // 无法整除n，跳过
            if ((na1 % n) != 0) {
                continue;
            }
            int a1 = na1 / n;
            List<Integer> seqList = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                seqList.add(a1++);
            }
            listList.addFirst(seqList);
        }
        int[][] ret = new int[listList.size()][];
        int count = 0; // 序列个数
        for (List<Integer> seq : listList) {
            ret[count++] = seq.stream().mapToInt(Integer::intValue).toArray();
        }
        return ret;
    }
}
```
