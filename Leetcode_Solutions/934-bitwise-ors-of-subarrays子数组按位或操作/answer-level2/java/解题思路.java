# 第一想法当然是 dp

     * 
     * 二维数组 B[i][j] 表示 A 从 i 到 j 的 或结果
     * 那么 B[i][j] = B[i][j-1] | B[i][j]
     * 
     * i: 0 -> n-1
     *      B[i][i] = A[i]
     *      j: 0 -> i-1
     *          B[j][i] = B[j][i-1] | A[i]
     *          
     * 统计所有不同的 B[j][i] 即可
     * 
     * 因为所有只是用了上一次的结果，统计不同值的数量，所以可以直接优化为一维数组
     * 
     * i: 0 -> n-1
     *      B[i] = A[i]
     *      j: 0 -> i-1
     *          B[j] = B[j] | A[i]  //这一次的结果等于上一次
     *          resultSet.add(B[j])

实现也很简单，但是提交超时

```
public int subarrayBitwiseORs(int[] A) {
    if (A == null || A.length < 1) {
        return 0;
    }
    int n = A.length;
    int[] B = new int[n];
    B[0] = A[0];
    Set<Integer> set = new HashSet<>();
    set.add(A[0]);
    for (int i = 1; i < n; i++) {
        B[i] = A[i];
        set.add(B[i]);
        for (int j = 0; j < i; j++) {
            B[j] = B[j] | A[i];
            set.add(B[j]);
        }
    }
    return set.size();
    }
```

# 优化思路

稍微 debug 一下就发现 B 数组的值在从 0 -> n 的方向上有阶梯的趋势

看上面的解题代码也可以发现就是 `A[i] | (上一次的计算值)` 加入到结果集

因为是 `|` 计算, 如果有变动一定是 0 变成 1，所以结果一定是大于 或 之前的结果

每一次循环不一定要计算所有位置上的值，只需要计算增加过的值即可

```
class Solution {
    public int subarrayBitwiseORs(int[] A) {
        int n = A.length;
        Set<Integer> set = new HashSet<>(n * 3);
        List<Integer> list = Collections.emptyList();
        for (int i = 0; i < n; i++) {
            List<Integer> nextList = new ArrayList<>(list.size() + 1);
            int pre = A[i];
            set.add(pre);
            nextList.add(pre);
            for (int x : list) {
                int v = pre | x;
                if (v > pre) {
                    nextList.add(v);
                }
                pre = v;
                set.add(pre);
            }
            list = nextList;
        }
        return set.size();
    }
}
```

![image.png](https://pic.leetcode-cn.com/2c33ae78083091ba8f090edfd9efcf28ec25024d7b679182e13234a77fd57915-image.png)
