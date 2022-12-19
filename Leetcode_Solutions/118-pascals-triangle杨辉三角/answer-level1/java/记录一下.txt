### 解题思路
# 起初想法，在进行计算之前的row首位添加0 然后进行连续两个数相加，结果添加进入新的row
# 发现引用使得整个二维数组都包含了0，最后发现0的作用其实就是为了添加收尾的1，所以直接add（1）避免修改row

### 代码

```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<Integer> row = new LinkedList<>();
        List<List<Integer>> angle = new LinkedList<>();
        if (numRows == 0) return angle;
        row.add(1);
        angle.add(row);
        while(numRows > 1){
            List<Integer> newRow = new LinkedList<>();
            newRow.add(1);
            for(int i = 0,j = i + 1;j < row.size(); ++i,++j){
                newRow.add(row.get(i) + row.get(j));
            }
            newRow.add(1);
            angle.add(newRow);
            row = newRow;
            --numRows;
        }
        return angle;

    }
}
```