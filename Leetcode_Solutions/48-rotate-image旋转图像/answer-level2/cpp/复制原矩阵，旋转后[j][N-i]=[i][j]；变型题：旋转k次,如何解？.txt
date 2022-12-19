算法思路：记原矩阵为A，旋转后为B；仔细分析，你发现A矩阵的第i行变为B矩阵第N-i列（见下图）。所以，1）先将原矩阵复制一份暂存于temp，2）遍历原矩阵每一个位置，则有matrix[j][N-i]=temp[i][j]。
![图片2.png](https://pic.leetcode-cn.com/e2099cb7c6f8ef5f421f6cfa10dcadf54d6aaed31cf33866c5e1a72e2bde2836-%E5%9B%BE%E7%89%872.png)

复杂度分析：时间复杂度O(n^2)，同时也是Ω(n^2)；空间复杂度O(n^2).
```
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N=matrix.size()-1;
        vector<vector<int>>temp=matrix;
        for(int i=0;i<=N;i++){
            for(int j=0;j<=N;j++){
                matrix[j][N-i]=temp[i][j];
            }
        }
        return;
    }
};
```
运行结果：依次运行显示均在50%以上。

变型题：在原题其他要求都不变的条件下，旋转k次，求旋转后的矩阵。
算法分析：1）显然易分析得旋转四次为一个周期，所以只需要求int k=k%4即可；2）在原来题目的基础上外加一层循环，对矩阵进行循环k次操作，或者每次计算一个单元时直接选择住那换后的坐标:
k=0,时无需变化;
k=1时,matrix[j][N-i]=temp[i][j];
k=2时,matrix[N-i][N-j]=temp[i][j];
k=3时,matrix[N-j][i]=temp[i][j];

所以程序可在原文的基础上改为：
```
class Solution {
public:
    void rotate(vector<vector<int>>& matrix,int k) {
        int k=k%4;
        if(!k){
            return;
        }
        int N=matrix.size()-1;
        vector<vector<int>>temp=matrix;
        for(int i=0;i<=N;i++){
            for(int j=0;j<=N;j++){
                int i1,j1;
                if(k==1){
                    i1=j,j1=N-i;
                }
                else if(k==2){
                    i1=N-i,j1=N-j;
                }
                else{
                    i1=N-j,j1=i;
                }
                matrix[i1][j1]=temp[i][j];
            }
        }
        return;
    }
};
```

