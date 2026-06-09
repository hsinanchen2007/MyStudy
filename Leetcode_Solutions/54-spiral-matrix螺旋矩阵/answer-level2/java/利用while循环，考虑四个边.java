### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private void addElment(List<Integer> list,int[][] matrix,
        int startRow,int endRow,int startColumns,int endColumns){
        if(startRow >endRow || startColumns >endColumns){return;}
        int startRow0=startRow;
        int endRow0=endRow;
        int startColumns0=startColumns;
        int endColumns0=endColumns;
        while (startColumns0 <= endColumns0){
            list.add(matrix[startRow0][startColumns0]);
            startColumns0++;
        }
        if(startRow0==endRow0){
            return;
        }
        int startRow1=startRow+1;
        int endRow1=endRow;
        int startColumns1=startColumns;
        int endColumns1=endColumns;
        while (startRow1 <endRow1){
            list.add(matrix[startRow1][endColumns1]);
            startRow1++;
        }
        int startRow2=startRow;
        int endRow2=endRow;
        int startColumns2=startColumns;
        int endColumns2=endColumns;
        while (endColumns2 >= startColumns2){
            list.add(matrix[endRow2][endColumns2]);
            endColumns2--;
        }
        int startRow3=startRow;
        int endRow3=endRow-1;
        int startColumns3=startColumns;
        int endColumns3=endColumns;
       while (endRow3 >startRow3 && startColumns3!=endColumns3){
            list.add(matrix[endRow3][startColumns3]);
            endRow3--;
        }

    }
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list =new ArrayList<>();
        if(matrix ==null|| matrix.length==0){
            return list;
        }
        int startRow=0;
        int endRow=matrix.length-1;
        int startColumns=0;
        int endColumns=matrix[0].length-1;

        while (startRow<=endRow){
             addElment(list,matrix,startRow,endRow,startColumns,endColumns);
             startRow=startRow+1;
             endRow=endRow-1;
             startColumns=startColumns+1;
             endColumns=endColumns-1;
        }
        return list;
    }
}
```