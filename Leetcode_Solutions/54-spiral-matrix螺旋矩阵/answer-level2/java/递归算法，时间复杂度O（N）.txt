特别注意的是：递归结束的条件：按照顺时针进行遍历，最终剩下的长方形的形状可能有三种情况：
设矩阵是m×n
1.如果原矩阵是偶数阶方阵---》最后剩下的形状为空
2.如果m>n----》剩下的是一个行向量
3.如果m<n---》剩下的是一个列向量
对上面递归结束的条件分别进行描述，如下代码所示：
```
class Solution {
     public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res= new ArrayList<>();
        if(matrix == null || matrix.length == 0) return res;
        return spiralOrderCore(matrix,0,matrix.length-1,
                0,matrix[0].length-1,res);
    }
    public List<Integer> spiralOrderCore(int[][] matrix,int up,int down,int left,int rigth,List<Integer> res){
        //递归结束的条件
        if(up == down && left<=rigth){
            for (int i = left; i <=rigth ; i++)
                res.add(matrix[up][i]);
            return res;
        } else if(left == rigth && up<=down){
            for (int i = up; i <=down ; i++)
                res.add(matrix[i][left]);
            return res;
        }else if(left>rigth || up>down)
            return res;
        for (int i = left; i <=rigth ; i++)
            res.add(matrix[up][i]);
        for (int i = up+1; i <=down; i++) //注意不可以重复
            res.add(matrix[i][rigth]);
        for (int i = rigth-1; i >=up ; i--)
            res.add(matrix[down][i]);
        for (int i = down-1; i >=up+1 ; i--)
            res.add(matrix[i][left]);
        return spiralOrderCore(matrix,up+1,down-1,
                left+1,rigth-1,res);
    }
}
```
