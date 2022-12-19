### 解题思路
一圈一圈的旋转，把每个元素放到相应的位置。注意，每一圈旋转时，行或列的不要把角上的元素重复旋转了。
时间复杂度是O(N^2),原地算法。执行时间和内存消耗都是100%。代码也很简短易读。

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int length=matrix.length;
        int top=0;
        int bottom=length-1;
        while(length>=0){
            for(int i=0;i<length-1;i++){
                int temp=matrix[top][top+i];
                matrix[top][top+i] = matrix[bottom-i][top];
                matrix[bottom-i][top]= matrix[bottom][bottom-i];
                matrix[bottom][bottom-i]=matrix[top+i][bottom];
                matrix[top+i][bottom]=temp;
            }
            length-=2;
            top+=1;
            bottom-=1;
        }
    }
}
```