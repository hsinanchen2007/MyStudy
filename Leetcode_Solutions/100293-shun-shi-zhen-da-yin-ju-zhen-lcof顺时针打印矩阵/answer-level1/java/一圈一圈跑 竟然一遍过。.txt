### 解题思路
执行用时 : 1 ms , 在所有 Java 提交中击败了 97.20% 的用户 
内存消耗 : 41.1 MB , 在所有 Java 提交中击败了 100.00% 的用户

### 代码

```java
class Solution {
    int[][] visitedMap ;
    public int[] spiralOrder(int[][] matrix) {
        if(matrix==null){
            return new int[0];
        }
        if(matrix.length==0||matrix[0].length==0){
            return new int[0];
        }
        visitedMap= new int[matrix.length][matrix[0].length];
        int[] result = new int[matrix.length*matrix[0].length];
        int index = 0;
        int i = 0;
        int j = 0;
        while(index<result.length){
            index = printCircle(matrix,i,j,index,result);
            i++;
            j++;
        }
        return result;
    }

    public int printCircle(int[][] matrix,int i, int j,int index,int[] result){
        while(j<matrix[0].length && visitedMap[i][j]==0){
            result[index] = matrix[i][j];
            visitedMap[i][j] = 1;
            j++;
            index++;
        }
        j--;
        i++;
        while(i<matrix.length && visitedMap[i][j]==0){
            result[index] = matrix[i][j];
            visitedMap[i][j]=1;
            i++;
            index++;
        }
        i--;
        j--;
        while(j>=0 && visitedMap[i][j]==0){
            result[index] = matrix[i][j];
            visitedMap[i][j]=1;
            j--;
            index++;
        }
        j++;
        i--;
        while(i>=0 && visitedMap[i][j]==0){
            result[index] = matrix[i][j];
            visitedMap[i][j]=1;
            i--;
            index++; 
        }

        return index;
    }
}
```