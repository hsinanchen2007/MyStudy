在数组不越界情况下,判断每个数字是否与下一行下标加一的数字是否相等.
不相等直接返回false

执行用时 :
4 ms
, 在所有 Java 提交中击败了
91.14%
的用户
内存消耗 :
42.5 MB
.
在所有 Java 提交中击败了
80.70%
的用户
```java 
for (int i = 0; i < matrix.length; i++) {
    for (int j = 0; j < matrix[i].length; j ++){
        if(i + 1 < matrix.length && j + 1 < matrix[i + 1].length){
            if(!(matrix[i][j] == matrix[i + 1][j + 1])){
                return false;
            }
        }
    }
}
```
