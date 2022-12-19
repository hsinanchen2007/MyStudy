### 解题思路

注意点：x==y情况需要特殊处理

### 代码

```java
class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
       int[][] array = new int[10][10];
       for(int i=0;i<dominoes.length; i++) {
           array[dominoes[i][0]][dominoes[i][1]]++;
       } 
       int count = 0;
       for(int i=0;i<dominoes.length; i++) {
           count += array[dominoes[i][0]][dominoes[i][1]] - 1;
           if(dominoes[i][0] != dominoes[i][1]) {
               count += array[dominoes[i][1]][dominoes[i][0]];
           }
       }
       return count/2;
    }
}
```