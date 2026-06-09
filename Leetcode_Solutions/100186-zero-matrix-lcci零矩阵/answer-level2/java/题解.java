### 解题思路
此处撰写解题思路

### 代码

```java
import java.util.*;
class Solution {
    public void setZeroes(int[][] matrix) {
        //这题主要就是先标记，在清除，不能一边扫描一遍清除
        HashSet<Integer> hang = new HashSet<>();
        HashSet<Integer> lie = new HashSet<>();
        for(int i = 0;i<matrix.length;i++){
            for(int j = 0;j<matrix[i].length;j++){
                if(matrix[i][j] == 0){
                    hang.add(i);
                    lie.add(j);
                }
            }
        }
        Iterator iterator = hang.iterator();
        int k = 0;
        while(iterator.hasNext()){
            k = (Integer)iterator.next();
            for(int j = 0;j<matrix[k].length;j++)
                matrix[k][j] = 0;
        }
        iterator = lie.iterator();
        while(iterator.hasNext()){
            k = (Integer)iterator.next();
            for(int j = 0;j<matrix.length;j++)
                matrix[j][k] = 0;
        }
    }
}
```
虽说时间上不太理想但是空间上还是可以的。
使用了set来防止重复。
分别记录下行和列。因为是唯一的所以在清零时小号的内存是较少的。但是时间上多少实惠有点消耗。