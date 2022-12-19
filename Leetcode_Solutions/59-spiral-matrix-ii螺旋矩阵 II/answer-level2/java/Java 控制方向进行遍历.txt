本题主要思路就是如何实现螺旋走位
注意到：向右走完一定向下，向下走完一定向左，向左走完一定向上，向上走完一定向右
所以只要限定每次移动到的边界在哪儿就行，然后每次走到头就更改方向
注意：上边界初始值应该是第二行（也就是下标索引的1）
有问题请批评指正
```java
class Solution {
    public int[][] generateMatrix(int n) {
        int i =0;
        int j =0;
        int direct = 0;//0:向右 1:向左 2:向下 3:向上
        int num = 1;
        int[][] matrix = new int[n][n];
        //四个边界
        int left = 0;
        int right = n-1;
        int up = 1;
        int down = n-1;

        while(num<=n*n){
            matrix[i][j] = num;
            num++;
            if(direct==0) j++;
            if(direct==1) j--;
            if(direct==2) i++;
            if(direct==3) i--;
            if(direct==0){
                if(j == right){
                    direct = 2;
                    right--;
                    }
            }
            else if(direct==1){
                    if(j == left){
                        direct = 3;
                        left++;
                        }
            }
            else if(direct==2){
                    if(i==down){
                        direct = 1;
                        down--;
                    }
            }
            else if(direct==3){
                    if(i==up){
                        direct = 0;
                        up++;
                    }
            }
        }
        return matrix;
    }
}
```
