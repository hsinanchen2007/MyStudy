### 执行结果
执行用时 :5 ms, 在所有 Java 提交中击败了64.09%的用户
内存消耗 :38.3 MB, 在所有 Java 提交中击败了94.17%的用户

### 解题思路
动态规划思想，从第二行元素开始，每个元素都更新为，和上一行相邻元素的最小值相加的结果，并在返回最后一行的最小值。
```
 1  2  3
 4  5  6
 7  8  9
--------
 1  2  3
 5  6  8
12 13 15
```


### 代码

```java
class Solution {
    public int minFallingPathSum(int[][] A) {
        
        if((A.length == 1) && (A[0].length == 0)){
            return 0;
        }
        
        int left = 0, right = 0, min = Integer.MAX_VALUE;

        for(int i=0; i<A.length; i++){

            for(int j=0; j<A[0].length; j++){
                
                if(i>0){
                    left = (j == 0) ? Integer.MAX_VALUE : A[i-1][j-1];
                    right = (j == A[0].length-1) ? Integer.MAX_VALUE : A[i-1][j+1];

                    A[i][j] += Math.min(Math.min(left, right), A[i-1][j]);
                }

                if(i == A.length-1 && min > A[i][j]){
                    min = A[i][j];
                }
            }
        }
        return min;
    }
}
```