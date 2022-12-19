### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int matrixScore(int[][] A) {
        //贪心法：第一列如果为0就翻转整行，因为第一个数占的权重比其他位合起来都多，结果翻转行之后行就不能再变了
        int sum=0;
        for(int i=0;i<A.length;i++)
        {
            if(A[i][0]==0)
                for(int j=0;j<A[0].length;j++)
                    A[i][j]=A[i][j]==0? 1:0;
            sum+=1<<(A[0].length-1);
        }
        //后面的每一列，计算当前列1的二进制和与0的二进制和，取较大的（即进行列翻转）
        for(int i=1;i<A[0].length;i++)
        {
            int zero_sum=0;
            int one_sum=0;
            for(int j=0;j<A.length;j++){
                if(A[j][i]==0)
                    zero_sum+=1<<(A[0].length-i-1);
                else
                    one_sum+=1<<(A[0].length-i-1);
            }
            sum+=Math.max(zero_sum,one_sum);
        }
        return sum;
    }
}
```