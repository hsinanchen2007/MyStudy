### 解题思路
注释

### 代码

```java
class Solution {
    public int matrixScore(int[][] A) {
        int res=(1<<(A[0].length-1))*A.length;//第一列全是1，直接加上
        for (int i=0;i<A.length;i++){//把第0列所有都变为1
            if (A[i][0]==0){
                for (int j=0;j<A[0].length;j++){
                    A[i][j]=1^A[i][j];
                }
            }
        }
        for(int i=1;i<A[0].length;i++){//统计每一列0,1个数，比较多的那个就是想要的数目
            int num=0;
            for (int j=0;j<A.length;j++) {
                if (A[j][i] == 0)
                    num++;
            }
            num=Math.max(num,A.length-num);//得出数目较多的数的数目
            res+=num*(1<<(A[0].length-1-i));//左移
        }
        return res;
    }
}
```