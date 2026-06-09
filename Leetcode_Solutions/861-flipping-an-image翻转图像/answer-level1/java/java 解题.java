### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        if(A==null) return null;
        int l = A.length;
        int[][] rev = new int[l][l];
        for(int i = 0; i<l ; i++){
            for(int j = 0;j<l ;j++){
                 if(A[i][j]==0) 
                 rev[i][l - 1 -j] =1;
                else  rev[i][l - 1 -j] =0;
                
            }
        
        }return rev;
    }
}
```