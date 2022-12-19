### 解题思路
要求对角线内元素的排序,所以只需遍历第一行与第一列即可

m,n坐标同时增加,将该线内元素添加到集合中,排序后替换原先数组中元素即可

只能想到简单的解法,高深的搞不定,要研究半天,求大佬带飞
ヾ(❀●◡●)ﾉ滴~儿童卡

### 代码

```java
class Solution {
    public int[][] diagonalSort(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;

        for(int i = 0; i < m; i++){
            getMaxN(i, 0, m, n, mat);
        }

        for(int j = 1; j < n; j++ ){
            getMaxN(0, j, m, n, mat);
        }

        return mat;
    }

    public void getMaxN(int i, int j, int m, int n, int[][] mat){
        if(i == m - 1 || j == n - 1){return;}
        List<Integer> list = new ArrayList<>();
        while(i < m && j < n){
            list.add(mat[i++][j++]);
        }
        Collections.sort(list);
        Collections.reverse(list);
        for(Integer t:list){
            mat[--i][--j] = t;
        }
    }
}
```