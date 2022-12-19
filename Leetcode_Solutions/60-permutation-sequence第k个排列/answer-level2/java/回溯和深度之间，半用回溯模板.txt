### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    List<Integer> list = new ArrayList();
    public String getPermutation(int n, int k) {
        int[] visit = new int[n];
        return backtrack(n, k, visit);
    }
    private String backtrack(int n, int k, int[] visit) {
        //1 递归终止条件
        if (list.size() == n) {
            String res = "";
            for (Integer i : list) {
                res += String.valueOf(i);
            }
            return res;
        }
        //2 根据已经选定的数的个数，进而确定还未选定的数的个数，然后计算阶乘，就知道这一个分支的叶子结点有多少个。
        int ps = factorial(n-1-list.size());
        for (int i = 0; i < n; i++) {
            //剪枝
            if (visit[i] == 1) continue;
            //如果 k 大于这一个分支将要产生的叶子结点数，直接跳过这个分支，这个操作叫“剪枝”
            if (ps < k) {
                k -= ps;
                continue;
            }
            list.add(i+1);
            visit[i] = 1;
            return backtrack(n, k,visit);
        }
        return "";
    }

    private int factorial(int n){
        int res = 1;
        for(int i = n; i > 1; i--){
            res *= i;
        }
        return res;
    }
}
```