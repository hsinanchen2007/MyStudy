### 解题思路
设置四个状态：1，2，3，4 对应向右，向下，向左，向上；
设置四个边界：toright，todown，toleft，totop，当遍历遇到边界时，转换状态；
**当向右赋值执行完时，开始向下赋值，并且上边界+1；
当向下赋值执行完时，开始向左赋值，并且右边界-1；
...以此类推**
赋完n*n个数就返回

### 代码

```java
class Solution {
    public int[][] generateMatrix(int n) {
        //开一个数组 N*N
        int data[][]=new int[n][n];
        //设置四种状态 ：右下左上..可以用swith结构
        //int[] stats={1,2,3,4};
        //设置右下左上四个边界，遇到边界边界就变1并且变相；
        int toright=n;
        int todown=n;
        int toleft=0;
        int totop=0;
        //按照规则不停执行，置数
        //设置一个数,用来置数
        int num=1;
        int row=0,column=0;
        int stats=1;//状态
        while(num<=n*n){
            switch(stats){
                case 1:
                //向右的
                    data[row][column]=num;
                    num++;
                    if(column+1==toright){
                        stats=2;
                        row++;
                        totop++;
                    }else{
                        column++;
                    }
                    break;//
                case 2:
                    data[row][column]=num;
                    num++;
                    if(row+1==todown){
                        stats=3;
                        column--;
                        toright--;
                    }else{
                        row++;
                    }
                    break;
                case 3:
                    data[row][column]=num;
                    num++;
                    if(column==toleft){
                        stats=4;
                        row--;
                        todown--;
                    }else{
                        column--;
                    }
                    break;
                case 4:
                    data[row][column]=num;
                    num++;
                    if(row==totop){
                        stats=1;
                        column++;
                        toleft++;
                    }else{
                        row--;
                    }
                    break;
            }
        }
        return data;
    }
}
```