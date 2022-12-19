让我们来一步一步的分析问题。

1.如果只旋转一个数而不覆盖其他的数，一共需要多少数跟着一起旋转？
答案：4个。例 [ [1,2,3], [4,5,6], [7,8,9] ]，如果旋转1，则3 9 7 都需要跟着动，即4个数

2.如果以4个数为一组，那么总共需要旋转多少组？
 答案：(n*n)/4,为什么是这么多组，很好理解，因为总共只有n* n个数，如果n是偶数，那么n* n一定是4的倍数，那么可以整除，如果是奇数，那么(n*n)/4余1，这个剩下的数，即中心，例[ [1,2,3], [4,5,6], [7,8,9] ]中的5。

3.如何划分(n*n)/4组？
答案：见下面代码的分组即可。看了就懂，因为这个分组有个原则，以前已经旋转的数，不能出现再出现在以后的旋转中。

4.4个一组的数有什么规律？
答案：现在数组matrix[i][j]= 原来数组matrix[n-1-j][i]，以这个规律不断替换即可


```
class Solution {
    public void rotate(int[][] matrix) {
        if(matrix==null||matrix.length==0)return;
        int n=matrix.length;
        for (int i = 0; i <n/2 ; i++) {
            for(int j=0;j<n/2+n%2;j++){
                int tmp=matrix[i][j];
                matrix[i][j]=matrix[n-1-j][i];
                matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
                matrix[j][n-1-i]=tmp;
            }
        }
    }
}
```
