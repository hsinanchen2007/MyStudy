**- 子问题：前i个数的等差数列组数**
- 前驱性：第i+1个数的加入不会对前i个数的等差数列组成造成影响
- 
- **转移方程：如果用dp[i]表示以第i+1个数为最后一个元素的所有等差数列数，问题：怎么区分公差不同的等差数列**
-   --改进：以dp[i][j]表示以A[i]-A[j]为公差
-   --得到：dp[i][j] = dp[j][k] + 1（A[i]-A[j] == A[j]-A[k]）
- 
- **k怎么得到：遍历前n个数或者用HashMap预处理**
-   --直接存储HashMap<A[i], i>的话，发现用例有重复 --> 用集合存储重复的A[i]
-   --还要考虑i、j、k的大小关系：i > j > k
- 
- 最后用例发现：加减之后，会出现大于int的数
-   --用long

```
public int numberOfArithmeticSlices(int[] A) {
    int[][] dp = new int[A.length][A.length];
    int res = 0;
    HashMap<Long, List<Integer>> checkup = new HashMap<>();   
    for (int i = 0; i < A.length; i++) {
        if (!checkup.containsKey((long)A[i])) checkup.put((long)A[i], new LinkedList<>());
        checkup.get((long)A[i]).add(i);
    }
    for (int i = 2; i < A.length; i++){
        for (int j = i - 1; j >= 0; j--){
            List<Integer> index_ls = checkup.getOrDefault((2*(long)A[j] - (long)A[i]), null);           
            if (index_ls != null){                   
                for (int index : index_ls)                      
                    if (index < j)  dp[i][j] += dp[j][index] + 1;      
            }
            res += dp[i][j];
        }
    }
    return res;
}
```
