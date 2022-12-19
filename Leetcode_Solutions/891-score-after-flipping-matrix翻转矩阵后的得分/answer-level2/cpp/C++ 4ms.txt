对于二进制数来说，我们只要保证最高位是1，就可以保证这个数是最大的，因为移动操作会使得它取反，因此我们进行行变化的时候只需要考虑首位即可。
对于后面的列处理，由于只影响的是该列，所以若要取得最大值，只需要保证该列1的个数 不少于0的个数即可。但是我们在进行列判断的时候，可以简化移动操作，因为这个过程我们会进行记录1的个数的计算，所以我们可以直接由1个个数去计算最后的总和即可。
```
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        if(A.empty()) return 0;
        int cos = A.size();//行
        int row = A[0].size();//列
        //行移动
        for(int i=0; i<cos; i++) {
            if(A[i][0] == 0) {//行翻转条件
                int index = 0;
                while(index<row) {
                    A[i][index] ^= 1;
                    index++;
                }
            }
        }
        
        int sum = cos * pow(2, row-1);//第一列全为1，sum初始值、
        for(int i=1; i<row; i++) {//按列计算
            int count = 0;
            for(int j=0; j<cos; j++) {
                if(A[j][i] == 1)//统计1的个数
                    count++;
            }
            if(count <= cos/2) {//列反转条件,不用进行翻转操作，直接计算
                count = cos - count;
            }
            sum += count * pow(2, row - i -1);
        }
        
        return sum;
    }
};
```
