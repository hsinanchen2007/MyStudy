### 解题思路
首先要通过演算推出赋值公式，我的草稿如下

![image.png](https://pic.leetcode-cn.com/a6d1b7daea5a12b7b8ecdc2ff86ae877a31e5be9d551e414837912857ffbdbb1-image.png)

每一步就是把 matrix[x][y]  赋值给 matrix[y][n-1-x]，之后就好说了。

预定义变量有这么几个
x , y 是矩阵的坐标，first用来指示x每次循环的起始点，temp用来记录每次会被覆盖的值（每循环一次就会递归四次，交换四个点位，用temp记录将要被覆盖但是下次递归需要的那个点位的值），number用来计数（每次循环递归只执行四次），n表示矩阵每一行的长度。
每次循环交换四个点位，每判断一次while就交换完每一圈的值，所以while的条件是 y<n/2 ，每次递归前把number置零，并用temp记录第一个交换的点位，用于给下个点位赋值。
在递归 change方法中先判断执行次数不大于四次（等于四次则说明每次for循环的四个点位已经交换完毕，就结束本次递归），之后就是先记录matrix[y][n-1-x] 的值用于下次交换，然后把之前记录的 matrix[x][y]的值赋值给 matrix[y][n-1-x]。
就这么简单

![image.png](https://pic.leetcode-cn.com/e009da3b1349b1766244c00f7d635af102c6279b149a20f50b45a4afd6ab9a3f-image.png)


### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int x =0,y=0,temp=0,number = 0,n = matrix.length;
        while(y<(n>>1)){
            for(x = y;x<n-1-y;x++){
                number = 0;
                temp = matrix[x][y];
                change(x,y,matrix,temp,n,number);
            }
            y++;
        }
    }

    private void change(int x,int y,int[][] matrix,int temp,int n,int number){
        if(number++==4)return;
        int tmp = matrix[y][n-1-x];
        matrix[y][n-1-x] = temp;
        change(y,n-1-x,matrix,tmp,n,number);
    } 
}

```
