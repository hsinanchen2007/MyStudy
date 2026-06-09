执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :39.3 MB, 在所有 Java 提交中击败了46.22%的用户
思路：求操作数组所构成的面积中重叠部分
```
class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        int max_i=40000,max_j=40000;         //将初始值设为最大
        if (ops.length==0){
            return m*n;
        }
        for (int i=0;i<ops.length;i++){
            if(ops[i][0]<max_i){
                max_i=ops[i][0];
            }
             if(ops[i][1]<max_j){
                max_j=ops[i][1];
            }
            
        }
        return max_i*max_j;
    }
}
```
