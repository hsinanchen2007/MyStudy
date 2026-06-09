### 解题思路
我的算法的关键变量是上下左右四个**界限变量**，以及一个当前**状态变量**state。
**state**可以取4个值，分别代表0向右移动，1向下移动，2向左移动，3向上移动。
**状态转移**
当前状态为0，遇到右边界限时，上界限下移，转移为状态1；
当前状态为1，遇到下边界限时，右界限左移，转移为状态2；
当前状态为2，遇到左边界限时，下界限上移，转移为状态3；
当前状态为3，遇到上边界限时，左界限右移，转移为状态0；


### 代码

```java
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] ret = new int[n][];
        for(int i=0;i<n;i++){
            ret[i] = new int[n];
        }
        int l = 0;
        int r = n-1;
        int up = 0;
        int down = n-1;
        int state = 0;
        int i=0,j=0;
        for(int k=1;k<= n*n;k++){
            ret[i][j] = k;
            switch(state){
                case 0:
                    if(j == r){
                        i++;
                        up++;
                        state = 1;
                    }
                    else j++;
                    break;
                case 1:
                    if(i == down){
                        j--;
                        r--;
                        state = 2;
                    }
                    else i++;
                    break;
                 case 2:
                    if(j == l){
                        i--;   
                        down--;
                        state = 3;
                    }
                    else j--;
                    break;
                 case 3:
                    if(i == up){
                        j++;  
                        l++;
                        state = 0;
                    }
                    else i--;
                    break;                       
            }
        }
        return ret;
    }
}
```