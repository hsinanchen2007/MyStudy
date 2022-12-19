### 解题思路
看到C语言的解题方法太少了，所以分享一下。
顺便吐槽一下C方式的接口变量确实很烦，需要这么多入口参数嘛？

简单来讲，就跟正常的二维数组遍历一样，两个for循环嵌套。稍微有点不同的有三点：
+ 外层循环`i`的最大边界是`(column + row)`，内层循环的`j`的最大边界是`i`
+ 遍历到的点要满足`arr[i - j][j]`, 也就是改点的行列坐标之和必须等于`i`
+ 奇偶行的遍历方向不同

![image.png](https://pic.leetcode-cn.com/b737f22a9a9b33b7200e7cbb81efae47e92b74d6356aa7f695fb877e545c6dfe-image.png)

### 代码

```c

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    /*入口参数检查省略
    ...
    * 局部变量定义省略
    ...
    * */
    
    /*因为奇数行偶数行遍历的方向相反，所以用一个flag区分*/
    int flag = 0;   // 
    for(int i = 0; i < row + col; i++) {
   
        if(flag%2 == 0) {      // 偶数行(0，2，4..)从左到右
            for(int j = 0; j <= i; j++) {
                if((i-j < row)&& j < col)   // 排除掉超出范围的点
                    MidArray[k++] = matrix[i - j][j];
            }
            flag = 1;
        }
        else {                 // 奇数行(1，3，5..)从右到左
            for(int j = i; j >= 0; j--) {
                if(j < col && (i-j < row))  // 排除掉超出范围的点
                    MidArray[k++] = matrix[i - j][j];
            }
            flag = 0;
        }   
    }
    return MidArray;
}
```