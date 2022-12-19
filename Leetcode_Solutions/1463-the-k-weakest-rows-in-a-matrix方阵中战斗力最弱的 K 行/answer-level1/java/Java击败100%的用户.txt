其实，就是一列一列的遍历数据，遇到0就将当前所在行号压入结果。最后，再补齐不够的部分。其中，需要一个flag数组来标记某行是否已经加入结果。代码如下：
```java
class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int[] res=new int[k];
        int count=0;
        boolean[] flag=new boolean[mat.length];
        for (int i=0;i<mat[0].length;++i){
            for (int j=0;j<mat.length;++j){
                if (count<k) {
                    if (!flag[j]&&mat[j][i]==0) {
                        res[count++]=j;
                        flag[j]=true;
                    }
                }else 
                    return res;
            }
        }
        if (count<k){
            //最后一列，从上到下遍历
            for (int i=0;i<mat.length&&count<k;++i){
                if (!flag[i])
                    res[count++]=i;
            }
        }
        return res;
    }
}
```
