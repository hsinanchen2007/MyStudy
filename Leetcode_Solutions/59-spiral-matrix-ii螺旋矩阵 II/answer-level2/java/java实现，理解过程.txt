和[徒手挖地球二四周目](https://blog.csdn.net/qq_42758551/article/details/104618018)的NO.54螺旋矩阵的处理方法类似，一层一层遍历，从左到右、由上到下、由右到左、由下到上从1开始每次自增1进行填充。

既然是四次方向变化，那么就需要四个"标记"分别标识上面一行，右边一列，下边一行，左边一列填充到的位置，标识分别叫做t，r，b，l。

有了标识之后从左向右就可以写作`for(i=l;i<=r;i++)`，即从左开始到右结束；遍历完上面这一行就将标识t++，即t行填充完毕。

```java
public int[][] generateMatrix(int n) {
    int[][] res=new int[n][n];
    int num=1,t=0,r=n-1,b=n-1,l=0;
    while (num<=n*n){
        //从左到右
        for (int i = l; i <= r; i++) res[t][i]=num++;
        t++;
        //从上到下
        for (int i = t; i <= b; i++) res[i][r]=num++;
        r--;
        //从右到左
        for (int i = r; i >= l; i--) res[b][i]=num++;
        b--;
        //从下到上
        for (int i = b; i >= t; i--) res[i][l]=num++;
        l++;
    }
    return res;
}
```

时间复杂度：O(n^2)

---

本人菜鸟，有错误请告知，感激不尽！

更多题解和学习记录博客:[博客](https://blog.csdn.net/qq_42758551)**、**[github](https://jerrymouse1998.github.io/) 