### 解题思路
![QQ截图20200326115404.png](https://pic.leetcode-cn.com/61c29b60068749c1a1e875208842448dfe2c6780a87db4d83694823a7bdbcd97-QQ%E6%88%AA%E5%9B%BE20200326115404.png)
详见注释
### 代码

```java
class Solution {
  public int numRookCaptures(char[][] board) {
       /*1.第一步，扫描所有棋子的坐标，放到一个数组里面，并记录车的坐标*/
        char [] arr = new char[64];
        int VR=9 , VC=9 ,count=0 , minleft=9 , minright=9 , minup=9 , mindown=9;
        for (int i = 0; i <board.length ; i++) {
            for (int j = 0; j <board[0].length ; j++) {
                char value = board[i][j];
                if (value!='.'){
                    int code = i*8 + j;
                    arr [code] = board[i][j];
                }
                if (value=='R'){
                    VR = i ; VC = j;
                }
                /*其实扫描到车的下方的第一颗子就完事了*/
                if (j==VC&&i>VR&&value!='.'){
                    break;
                }
            }
        }
        /*2.遍历棋子数组,找到所有离车最近的子的坐标*/
        char [] fina = new char[4];
        for (int i = 0; i <arr.length ; i++) {
            int row = i / 8 ;  int colum = i % 8 ;
            if (row!=VR&&colum!=VC||arr[i]==0){
                continue;
            }
            /*行相等，车左边*/
            if (colum<VC&&VC-colum<minleft){
                fina[0] = arr[i];
                minleft =  VC-colum;
            }
            /*行相等，车右边*/
            if (colum>VC&&colum-VC<minright){
                fina[1] = arr[i];
                minright = colum-VC;
            }
            /*列相等，车上边*/
            if (row<VR&&VR - row<minup){
                fina[2] = arr[i];
                minup = VR - row;
            }
            /*列相等，车下边*/
            if(row>VR&&row-VR<mindown){
                fina[3] = arr[i];
                mindown = row-VR;
            }
        }
        //已经得到离车最近的子的坐标，返回p的个数
        for (char v : fina )
           if (v=='p')
               count++;
        return  count ;
    }
}
```