
### 代码

```java
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        if(matrix.length == 0) return new int[0];
        int rStart = 0,rEnd = matrix.length - 1;
        int cStart = 0,cEnd = matrix[0].length - 1;
        int allNums = matrix.length * matrix[0].length;
        int[] res = new int[allNums];
        int count = 0;
        while(rStart <= rEnd && cStart <= cEnd){
            for(int c = cStart;c <= cEnd;c++) 
                res[count++] = matrix[rStart][c];
            for(int r = rStart+1;r <= rEnd;r++)
                res[count++] = matrix[r][cEnd];
            if(rStart < rEnd && cStart < cEnd){
                for(int c = cEnd - 1;c > cStart;c--)
                    res[count++] = matrix[rEnd][c];
                for(int r = rEnd;r > rStart;r--)
                    res[count++] = matrix[r][cStart];
            }
            cStart++;
            cEnd--;
            rStart++;
            rEnd--;
        }
        return res;
    }
}
```