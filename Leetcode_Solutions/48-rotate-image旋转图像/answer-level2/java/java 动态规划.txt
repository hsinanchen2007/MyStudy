### 解题思路
1、首先分析题目，我们可以把一个n*n的矩阵看做由内到外若干个正方形组成的环形数组
以四维数组为例
   [15,13, 2, 5],
    [14, 3, 4, 1],
    [12, 6, 8, 9],
    [16, 7,10,11]
其实是由[15 13 2 5]
         14        1        
         12        9
         16   7  10  11
   和
     [3  4]
      [6 8]
    组成的
   那么可以看出每减一次环,正方形的边长就-2
2、假定我们有了一个public void rotateCycle(int[][] matrix,int n)(n代表正方形的边长)旋转正方形的方法，那么问题就简化为:
   int length = matrix.length;
   for(int i=length;i>0;i-=2){
        //因为边长为1就是一个数字，不用旋转了
       if(i==1){
          return;
       }
       rotateCycle(matrix,i);
   }      
3、现在来实现public void rotateCycle(int[][] matrix,int n) 旋转正方形的方法
     我们以
         [15 13 2 5]
         14        1        
         12        9
         16   7  10  11
     为例，对正方形的第一条边 [15 13 2 5],每个数字又可以和相邻距离为n-1的数字组成一个小正方形
       例如:  15  5  
               16   11
              
            13    1
            12      10
          这个小正方形永远只有4个数字，所以问题又可以简化为对正方形的第一条边里不包含结尾的元素进行循环，每获得一个数字就对该数字组成的正方形进行旋转。
       int startColumn = 0+(matrix.length-n)/2
       int endColumn = mathrix.length-1-(matrix.length-n)
       int startRow = 0+(matrix.length-n)/2;
       int currentValue; 
       for(int = startColumn;i<endColumn;i++){
            current = mathrix[startRow][i]
           //旋转current的所在的正方形，正方形每个角相邻元素的距离是n-1(边长-1)
            //问题简化为右移一个固定的四位数组成的数组 15 5 11 16->16 15 5 11
                           
       }   
3、 假设我们有一个移动步长函数,返回值是移动后的坐标,第一项是横坐标，第二项是纵坐标
    //row,column代表我们挪动的元素的起始坐标，step表示要移动的步数,startRow,endRow代表这个每一层环形正方形的起始行和起始列,length代表环形正方形的边长  
    private int[][] runStep(int[][] matrix,int row,int column,int step,int startRow,int startColumn,int length){
      
      }        
     那么上面一个右移一个固定的四位数组成的数组 15 5 11 16->16 15 5 11的逻辑可以实现为:
     //先找到结尾那个元素,也就是要移动3*(length-1)步,这里稍微有一点不理想的地方就是第二次移动的轨迹涵盖了第一次移动的轨迹
     //currentValue = 15 
     int currentValue = matrix[row][column]
     int[][] targetVertex = runStep(matrix,row,column,3*(length-1),(matrix.length-n)/2,(matrix.length-n)/2,length);
     //target=16
     int target =  matrix[targetVertex[0]][targetVertex[1]];
     for(int i=1;i<=3;i++){
        //总共要移动3次,每次都以起始位置向前移动(length-1)*j
        int[][]  nextVertex =   runStep(matrix,row,column,j*(length-1),(matrix.length-n)/2,(matrix.length-n)/2,lnegth);   
         //把移动后的值记下来，作为下一次要赋值的值
         int tmp = matrix[nextVertex[0]][nextVertex[1]]
         //把当前位置的值用上一个值赋值
         matrix[nextVertex[0]][nextVertex[1]] = currentValue;     
         currentValue = tmp;
     }
     //上面做的操作是5->15,11->5,16->11,这时候再把16赋给15所在的坐标
      matrix[row][column] = target;
 4、最后我们就来实现  private int[][] runStep(int[][] matrix,int row,int column,int step,int startRow,int startColumn,int length){
      
      }
    这里的移动步长函数
    for(int index=1;index<=step;index++){
       //说明在正方形的最上面的一条边
       if(row==startRow&&column<startColumn+length-1){
          column+=1;
       }else if(column==startColumn+length-1&&row<startRow+length-1){
          //说明在正方形的最右边一条边
          row+=1; 
       }else if(row==startRow+length-1&&column>startColumn){
          //说明在正方形的最下边一条边
          column-=1;
       }else if(column==startColumn&&row>startRow){
          //说明在正方形的最左边一条边
          row-=1;
       } 
    }           
    return new int[]{row,column};
### 代码

```java
class Solution {
    private int[] runStep(int[][] matrix,int row,int column,int step,int startRow,int startColumn,int length){
        for(int index = 1;index<=step;index++){
            //在同一行里面
            if(row==startRow&&column<startColumn+length-1){
                column+=1;
                continue;
            }
            if(column==startColumn+length-1&&row<startRow+length-1){
                row+=1;
                continue;
            }
            if(row==startRow+length-1&&column>startColumn){
                column-=1;
                continue;
            }
            if(column==startColumn&&row>startRow){
                row-=1;
            }
        }
        return new int[]{row,column};
    }

    /**
     * n代表正方形的边长
     *
     * @param matrix
     * @param n
     */
    private void rotateCycle(int[][] matrix,int n){
        int length = matrix.length;
        int initRow = 0+(length-n)/2;
        int initColumn = initRow;
        //对角线的那个角落的坐标
        int endRow =  (length-1)-(length-n)/2;
        int endColumn = endRow;
        //先保存与之逆时针90度相邻的那个元素值
        int targetValue = 0;
        int currentValue = 0;
        for(int i = initColumn;i<endColumn;i++){
            currentValue = matrix[initRow][i];
            int[] targetVertex = runStep(matrix,initRow,i,3*(n-1),initRow,initColumn,n);
            targetValue = matrix[targetVertex[0]][targetVertex[1]];
            for(int j=1;j<=3;j++){
                int[] nextVertex = runStep(matrix,initRow,i,(n-1)*j,initRow,initColumn,n);
                int tmpValue = matrix[nextVertex[0]][nextVertex[1]];
                matrix[nextVertex[0]][nextVertex[1]] = currentValue;
                currentValue = tmpValue;
            }
            matrix[initRow][i] = targetValue;
        }
    }
    
    public void rotate(int[][] matrix) {
         int length = matrix.length;
        for(;length>0;length-=2){
            if(length==1){
                return;
            }
            rotateCycle(matrix,length);
        }
    }
}
```