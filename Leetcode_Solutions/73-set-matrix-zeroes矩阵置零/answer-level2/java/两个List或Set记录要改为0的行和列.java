1. 两个List的方法，给的测试用例List竟然比Set块。
```java
class Solution {
    public void setZeroes(int[][] matrix) {
        List<Integer> list1 = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();
        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                if(matrix[i][j] == 0){
                    if(!list1.contains(i)) list1.add(i);
                    if(!list2.contains(j)) list2.add(j);
                }
            }
        }
        for(int i = 0; i < list1.size(); i++){
            for(int j = 0; j < matrix[0].length; j++){
                matrix[list1.get(i)][j] = 0;
            }
        }
        for(int i = 0; i < list2.size(); i++){
            for(int j = 0; j < matrix.length; j++){
                matrix[j][list2.get(i)] = 0;
            }
        }
    }
}
```
2. 两个Set的方法
```java
class Solution {
    public void setZeroes(int[][] matrix) {
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();
        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                if(matrix[i][j] == 0){
                    set1.add(i);
                    set2.add(j);
                }
            }
        }
        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                if(set1.contains(i) || set2.contains(j)){
                    matrix[i][j] = 0;
                }
            }
        }
    }
}
```