因为每个数都在1—9之间，所以用一个9×9的矩阵`flag`用来记录等价多米诺骨牌的数量。其中，`flag[i][j]`表示多米诺骨牌`[i,j]`(或者是`[j,i]`,需要始终保持骨牌[a,b]中a大于b)。统计结束后，对于大于2个的骨牌数n，其等价多米诺的对数应该是(组合数公式)
```
 n
C
 2
```
代码如下：
```java
    public int numEquivDominoPairs(int[][] dominoes) {
        int[][] flag=new int[9][9];
        for (int[] row:dominoes){
            if (row[0]>row[1]){
                flag[row[1]-1][row[0]-1]++;
            }else {
                flag[row[0]-1][row[1]-1]++;
            }
        }
        int count=0;
        for (int[] row:flag){
            for (int item:row){
                if (item>1)
                    count+=item*(item-1)/2;
            }
        }
        return count;
    }
```
