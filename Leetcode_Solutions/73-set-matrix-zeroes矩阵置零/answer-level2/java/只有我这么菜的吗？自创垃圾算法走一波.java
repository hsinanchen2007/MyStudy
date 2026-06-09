### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void setZeroes(int[][] matrix) {
        List<Integer> list = new ArrayList<>();
        for(int i = 0;i < matrix.length;i++){
            for(int j = 0;j < matrix[i].length;j++){
                if(matrix[i][j] == 0){
                    list.add(i);
                    list.add(j);
                }
            }
        }
        setZ(matrix,list);
    }

    public static void setZ(int[][] arr,List<Integer> list){
        int i = 0;
        while(i <= list.size() - 1){
            int a = list.get(i);
            int b = list.get(i + 1);
            for(int h = 0;h < arr[0].length;h++){
                arr[a][h] = 0;
            }
            for(int k = 0;k < arr.length;k++){
                arr[k][b] = 0;
            }
            i += 2;
        }
    }
}
```