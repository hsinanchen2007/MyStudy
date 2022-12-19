仔细观察数组旋转后会发现如下规律
`[i,j]-->[j,size-1-i]-->[size-1-i,size-1-j]-->[size-1-j,i]-->[i,j]`

故只需要遍历一半的矩阵规模，在遍历时一次性交换相关值即可，此后无需在此交换。
。
这里采用位运算的方式交换两个值。
```
 //使用位运算中的异或，俩次异或不改变原值  
        a = a^b;  
        b = a^b;  
        a = a^b; 
```
由于矩阵的规模N不同时，遍历的情况不同，所以为了兼容，第一个for中size多加了一个1.
代码如下：
```
void rotate(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return;
        for(int i=0;i<(matrix.size()+1)/2;i++)
        {//只需要处理矩阵的一半就行了
            for(int j=0;j<matrix[0].size()/2;j++)
            {
                //[i,j]->[j,size-1-i]->[size-1-i,size-1-j]->[size-1-j,i]->[i,j]
                //交换数据
                matrix[i][j]=matrix[i][j]^matrix[j][matrix.size()-i-1];
                matrix[j][matrix.size()-1-i]=matrix[i][j]^matrix[j][matrix.size()-i-1];
                matrix[i][j]=matrix[i][j]^matrix[j][matrix.size()-i-1];
                //交换数据
                matrix[matrix.size()-1-i][matrix.size()-1-j]=matrix[matrix.size()-1-i][matrix.size()-1-j]^matrix[matrix.size()-1-j][i];
                matrix[matrix.size()-1-j][i]=matrix[matrix.size()-1-i][matrix.size()-1-j]^matrix[matrix.size()-1-j][i];
                matrix[matrix.size()-1-i][matrix.size()-1-j]=matrix[matrix.size()-1-i][matrix.size()-1-j]^matrix[matrix.size()-1-j][i];
                //交换数据
                matrix[i][j]=matrix[i][j]^matrix[matrix.size()-1-i][matrix.size()-1-j];
                matrix[matrix.size()-1-i][matrix.size()-1-j]=matrix[i][j]^matrix[matrix.size()-1-i][matrix.size()-1-j];
                matrix[i][j]=matrix[i][j]^matrix[matrix.size()-1-i][matrix.size()-1-j];
            }
        }
        return;
    }
```
