### 解题思路
首先 交换不消耗额外内存 思路
针对2个int a，b
a = a+b;
b = a-b;
a = a-b;

于是有了方法 exc3 用于交换矩阵内2点
其次找点，不难发现，每一个点，都对应矩阵内其他三点会进行移动交换
可以发现规律为 设矩阵长为 length,任意点i,j  4个对应点为
i,j  j,length-1-i   length-1-i,length-1-j   length-1-j,i
即 当前点i,j 旋转后的下一个点位置为j,a-1-i
4点旋转，只需要交换3次
若以顺时针1，2，3，4表示4点
交换1，2
交换1，3
交换1，4
就能完成4点旋转

最后是循环遍历次数
寻找规律发现，外层循环，
只需要 矩阵长 length/2 次即可
所以有
for(int i=0;i<length/2;i++){
    xxxxxx
}
内层循环，遍历每一行，观察发现for(int j=i;j<length-i-1;j++){
}
（原谅我实在不晓得咋个解释）
### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
                int length = matrix.length;
        for(int i=0;i<length/2;i++){
            for(int j=i;j<length-i-1;j++){
                exc3(matrix,i,j,j,length-1-i);
                exc3(matrix,i,j,length-1-i,length-1-j);
                exc3(matrix,i,j,length-1-j,i);
            }
        }
    }

    public void exc3(int arr[][],int i1,int j1,int i2,int j2){
        arr[i1][j1] = arr[i1][j1]+arr[i2][j2];
        arr[i2][j2] = arr[i1][j1]-arr[i2][j2];
        arr[i1][j1] = arr[i1][j1]-arr[i2][j2];
    }
}
```