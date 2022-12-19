### 解题思路
就正常写。。没啥技术含量，愿意看就看看吧，比较容易理解。

### 代码

```java
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        for(int i = 0;i<A.length;i++) {
            int temp = 0;
            for(int j = 0;j<A[0].length/2;j++) {
                temp = A[i][j];
                A[i][j] = A[i][A[0].length-1-j];
                A[i][A[0].length-1-j] = temp;
            }
        }
        for(int i = 0;i<A.length;i++) {
            for(int j = 0;j<A[0].length;j++) {
                if(A[i][j] == 0) A[i][j]=1;
                    else A[i][j] = 0;
            }
        }
        return A;
    }
}
```