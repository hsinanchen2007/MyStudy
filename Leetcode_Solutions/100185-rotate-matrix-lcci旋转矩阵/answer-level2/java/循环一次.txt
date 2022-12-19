### 解题思路
难得双100%，理解起来复杂一点 但只循环一次。 i行j列==>j行len-i列， j行len-i列==>len-i行len-j列， len-i行len-j列==>len-j行i列， len-j行i列==>i行j列， 详细参考注释

### 代码

```java
class Solution {
   public void rotate(int[][] matrix) {
        int len = matrix.length;
        if (len == 0) return;
        int temp1 = 0;
        int temp2 = 0;
        int imax= len%2==0? len/2:len/2+1;
         for (int i = 0; i < len/2; i++) {
            for (int j = i; j < len-1-i; j++) {
                //a...b
                //.....
                //d...c
                //temp1=a;a=d;temp2=b;b=temp1=a;temp1=c;c=temp2;d=temp1=c;
                //len-1-j,i ==> i, j
                //i,j==> j,len-1-i
                //j,len-1-i==>len-1-i,len-1-j
                //len-1-i,len-1-j==>len-1-j,i 
                temp1 = matrix[i][j];
                matrix[i][j] = matrix[len-1 - j][i];
                temp2= matrix[j][len-1-i];
                matrix[j][len-1-i] = temp1;
                temp1 = matrix[len-1-i][len-1-j];
                matrix[len-1-i][len-1-j] = temp2;
                matrix[len-1 - j][i] = temp1;
                
                
            }
        }
    }
}
```