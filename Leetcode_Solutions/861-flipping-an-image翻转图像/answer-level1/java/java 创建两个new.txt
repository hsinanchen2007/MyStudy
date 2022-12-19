### 解题思路
对于1和0的翻转，有两种思路
用 1 - 当前值，得到的就是0和1的翻转
用 1 ^ 当前值，得到的也是0和1的反转。这个符号是异或，相同为0，相异为1
用两个幼稚的If

### 代码

```java
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        int[][] B=new int[A.length][A[0].length];
        int[][] C=new int[A.length][A[0].length];
        for(int i=0;i<A.length;i++){
            for(int m=0;m<A[i].length;m++) {
                B[i][m] = A[i][A[i].length - m - 1];
                if(B[i][m]==1) C[i][m]=0;
                if(B[i][m]==0) C[i][m]=1;
            }
        }
        return C;
    }
}
```