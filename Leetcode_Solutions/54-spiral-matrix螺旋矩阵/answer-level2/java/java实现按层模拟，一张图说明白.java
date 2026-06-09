从[0\][0\]开始模拟顺时针一层一层的遍历所有元素。

![question54 1.png](https://pic.leetcode-cn.com/0086608affe5321972270e17d9a48c00433172300195cc046b96c92d7c2d89c4-question54%201.png)


计算层数count：`(Min(row，col)+1)/2`，因为每次最多有两行两列组成，最少由一行或一列组成。

遍历每一层curr即`[0,count)`，每层有四次"转弯"：

1. 每一层先从左到右遍历一行，即`for(i=curr;i<col-curr;i++)matrix[curr][i]`。
2. 再从上到下遍历一列，即`for(i=curr+1;i<row-curr;i++)matrix[i][col-1-curr]`。
3. 再从右到左遍历一行，即`for(i=col-1-curr-1;i>=curr;i--)matrix[row-1-i][i]`。
4. 最后从下到上遍历一列，即`for(i=row-1-curr-1;i>=curr+1;i--)matrix[i][curr]`。

*ps：每一层除了第一行是遍历一整行元素，其余三部分都需要注意不要重复遍历"拐点"元素。*

上述是常规层(两行两列)的遍历；如果只有一行，从右向左遍历时会重复遍历；如果只有一列，从下向上遍历时会重复遍历，如何解决这个问题？

答：只有一行或只有一列时，不进行右向左或下向上的遍历即可。如何判断？`row-1-curr==curr`说明当前层只有一行；`col-1-curr==curr`说明当前层只有一列。

```java
public List<Integer> spiralOrder(int[][] matrix) {
    List<Integer> res=new ArrayList<>();
    if (matrix==null||matrix.length==0)return res;
    int row = matrix.length,col=matrix[0].length;
    //计算有多少层
    int count=(Math.min(row,col)+1)/2;
    //当前层
    int curr=0;
    //遍历每一层
    for (;curr<count;curr++){
        //从左向右
        for (int i = curr; i < col - curr; i++) {
            res.add(matrix[curr][i]);
        }
        //从上到下
        for (int i = curr+1; i < row-curr; i++) {
            res.add(matrix[i][col-1-curr]);
        }
        //从右到左
        for (int i = col-1-curr-1; i >= curr&&(row-1-curr!=curr); i--) {
            res.add(matrix[row-1-curr][i]);
        }
        //从下到上
        for (int i = row-1-curr-1; i >= curr+1&&(col-1-curr!=curr); i--) {
            res.add(matrix[i][curr]);
        }
    }
    return res;
}
```

时间复杂度：O(n)

---

本人菜鸟，有错误请告知，感激不尽！

更多题解和学习记录博客:[博客](https://blog.csdn.net/qq_42758551)**、**[github](https://jerrymouse1998.github.io/) 