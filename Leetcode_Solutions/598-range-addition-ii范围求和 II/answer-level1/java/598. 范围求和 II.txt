/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/26
 *
 * 解题思路: 怎么想 怎么做 就是查找ops框起来的最小矩形的单位面积 x最小的 y最小的 x*y 返回
 *
 * 注意: 如果ops 为空 那么直接m*n 全部都是0
 *
 */
```
public int maxCount(int m, int n, int[][] ops) {
    if(ops.length == 0){
        return m*n;
    }

    int x = Integer.MAX_VALUE;
    int y = Integer.MAX_VALUE;
    for(int i = 0;i < ops.length;i++){
        if(ops[i][0] < x) x = ops[i][0];
        if(ops[i][1] < y) y = ops[i][1];
    }
    return x*y;
}
```