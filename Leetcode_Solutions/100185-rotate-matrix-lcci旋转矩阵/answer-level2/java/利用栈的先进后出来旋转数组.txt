### 解题思路
以第一列为例，旋转90度，变成了第一行。依据栈的先进后出原则，如果需要第一列的最后一个元素变成第一个输出的，则需要最后将它压入。所以按照逆序竖列压入栈的时候才能保证出栈的时候按照顺序横行出栈，实现旋转90度。

### 代码
```java
class Solution {
    public void rotate(int[][] matrix) {
        int column = matrix[0].length;
        int row = matrix.length;
        Stack st = new Stack();
        for(int j=column-1; j>=0; j--){
            for(int i=0; i<row; i++){
                st.push(new Integer(matrix[i][j]));
            }
        }   
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                matrix[i][j] = Integer.parseInt(st.peek().toString());
                st.pop();
            }
        }    
    }
}
```