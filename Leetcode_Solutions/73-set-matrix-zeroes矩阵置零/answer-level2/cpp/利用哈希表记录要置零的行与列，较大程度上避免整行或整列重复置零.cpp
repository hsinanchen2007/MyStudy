算法思路：
1）设置两个数组hashi[矩阵行数]和hashj[家族很列数],均初始化为0；hashi[i]不为0表示矩阵第i行有0，同理hashj[j]不为0表示矩阵第j行有0。
2）遍历矩阵，当[i][j]为0时，hashi[i]=1， hashj[j]=1。
3）遍历hashi，若hashi[i]不为0，将矩阵第i行循环置零；
4）遍历hashj，若hashj[j]不为0，将矩阵第j列循环置零；

算法性能分析：
时间复杂度：第1）步，时间开销为a(N+M)；第2)步时间开销最小最大均为bN*M，第3）步时间最大开销为cN*M，最小开销为cN;第4）步时间最大开销为dN*M，最小开销为dM。合计所以最坏复杂度为a(N+M)+bN*M+cN*M+dN*M,最好复杂度为：a(N+M)+bN*M+cN+dM。其中a、b、c、d均为每一步的平均常数因子。可见算法稳定性较高。
空间复杂度：
最好最坏都是N+M,即θ(N+M)。
```
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(!matrix.size()){
            return;
        }
        int N=matrix.size()-1;
        int M=matrix[0].size()-1;
        vector<int>hashi(N+1,0);
        vector<int>hashj(M+1,0);
        for(int i=0;i<=N;i++){
            for(int j=0;j<=M;j++){
                if(!matrix[i][j]){
                    hashi[i]=1;
                    hashj[j]=1;
                }
            }
        }
        for(int i=0;i<=N;i++){
            if(hashi[i]){
                for(int j=0;j<=M;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=0;j<=M;j++){
            if(hashj[j]){
                for(int i=0;i<=N;i++){
                    matrix[i][j]=0;
                }
            }
        }    
    }      
};
```
