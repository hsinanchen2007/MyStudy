bfs
首先建立队列存入所有0 的位置
依次出队并访问这些0 的四周，
生成<=4个子位置，将子位置放入队列
之后出队
结束就是队列为空的时候
import javafx.util.Pair;


import java.util.LinkedList;

class Solution {
       public int[][] updateMatrix(int[][] matrix) {
        int rowlength =matrix.length;
        int clolength = matrix[0].length;

        LinkedList<Pair<Integer,Integer>> queue = new LinkedList<>();
        for (int i=0;i<rowlength;i++){

            for (int j=0;j<clolength;j++){

                if(matrix[i][j]==0){
                    //存入所有包含0 的点
                    Pair<Integer,Integer> zero = new Pair<>(i,j);
                    queue.add(zero);
                }else{
                    //初始化
                    matrix[i][j]=-1;
                }


            }

        }
        //queue store all the zero point


        while (!queue.isEmpty()){
            Pair<Integer,Integer> now = queue.pop();
            //left
            if(now.getKey()-1>=0&& matrix[now.getKey()-1][now.getValue()]==-1){
                matrix[now.getKey()-1][now.getValue()]=matrix[now.getKey()][now.getValue()]+1;

                Pair<Integer,Integer> zero = new Pair<>(now.getKey()-1,now.getValue());
                queue.add(zero);

            }
            //right
            if(now.getKey()+1<rowlength&&matrix[now.getKey()+1][now.getValue()]==-1){
                matrix[now.getKey()+1][now.getValue()]=matrix[now.getKey()][now.getValue()]+1;

                Pair<Integer,Integer> zero = new Pair<>(now.getKey()+1,now.getValue());
                queue.add(zero);
            }
            if(now.getValue()-1>=0&&matrix[now.getKey()][now.getValue()-1]==-1){
                matrix[now.getKey()][now.getValue()-1]=matrix[now.getKey()][now.getValue()]+1;

                Pair<Integer,Integer> zero = new Pair<>(now.getKey(),now.getValue()-1);
                queue.add(zero);
            }
            if(now.getValue()+1<clolength&& matrix[now.getKey()][now.getValue()+1]==-1){
                matrix[now.getKey()][now.getValue()+1]=matrix[now.getKey()][now.getValue()]+1;

                Pair<Integer,Integer> zero = new Pair<>(now.getKey(),now.getValue()+1);
                queue.add(zero);
            }

        }
        return matrix;



    }
}