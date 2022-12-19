# 思路
1. 先升序排序。
2. 暴力法：
**外层**循环:当前需要被凑成的数`base`，
**内层**循环:在比`base`小的数中，寻找`base`能**整除**的数`temp_num`，且`base`除以`temp_num`的**结果**(记为`temp_result`)也要出现在数组中(利用哈希判断即`containsKey()`)。
若满足上述条件，则`base`的计数 += `temp_num`的计数 * `temp_result`的计数。

注意：要`mod 1000_000_007`。

# 代码
```java
class Solution {
    public int numFactoredBinaryTrees(int[] A) {
        int len = A.length, mod = 1000_000_007;
        HashMap<Integer, Long> map = new HashMap<>(len);
        for (int num : A)
            map.put(num, 1L);
        Arrays.sort(A);
        for (int i = 1; i < len; ++i) {
            int base = A[i];
            for (int j = 0; j < i; ++j)
                if (base % A[j] == 0) {
                    int another = base / A[j];
                    if (map.containsKey(another))
                        map.merge(base, map.get(another) * map.get(A[j]), (o_val, n_val) -> (o_val + n_val) % mod);
                }
        }
        long res = 0;
        for (long num : map.values())
            res = (res + num) % mod;
        return (int) res;
    }
}
```
