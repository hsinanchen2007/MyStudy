从头开始，从左到右，从上到下，依次遍历每个节点。

当我们发现有一个'1'节点m[i][j],就以这个节点为起点，查找它对应得所有矩形的面积。

首先查找以m[i][j]为起点，宽度为1的矩形。我们从当前第i层向下遍历，如果下一个格子值为'1'，那么矩形面积加1。如果下一个格子是'0',那么我们找到了以m[i][j]为起点，宽度为1的最大矩形。

然后从m[i][j]向右，如果下一个节点为'1'，那么我们就查找宽度为2的矩形，也就是以i和i+1为左右边界的矩形。

从第i层向下遍历，如果下一层左右边界为i和i+1的格子都为‘1’，那么矩形的面积加2。
如果下一层格子有'0'，那么我们找到了以m[i][j]为起点，宽度为2的最大矩形。与前面宽度为1的矩形比较，记录较大的值；

从上面的m[i+1][j]继续向右，以此类推。
直到m[i][j]右面的节点为'0',我们已经找到了以m[i][j]为起点的最大矩形。



然后寻找下个起点，从左到右，从上到下，以此类推，直到遍历完所有的格子，我们就找到了矩阵中最大的矩形。
```
class Solution {
        public int maximalRectangle(char[][] matrix) {
            int max=0;
            for(int i=0;i<matrix.length;i++){
                for(int j=0;j<matrix[0].length;j++){
                    if(matrix[i][j]=='1'){
                        int k=j;
                        for(;k<matrix[0].length;k++){
                            if(matrix[i][k]=='1'){
                                max=Math.max(max,getMaxRec(i,j,k,matrix));
                            }else{
                                break;
                            }
                        }
                    }
                }
            }
            return max;
        }

        public int getMaxRec(int i,int j,int k,char[][] matrix){
            int s=k-j+1;
            int r=s;
            for(int i1=i+1;i1<matrix.length;i1++){
                for(int j1=j;j1<=k;j1++){
                    if(matrix[i1][j1]=='0'){
                        return r;
                    }
                }
                r+=s;
            }
            return r;
        }
    }
```
