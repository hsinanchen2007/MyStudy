```
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /*
        总结：对于一个5x5矩阵          旋转的过程如下
            [00 01 02 03 04]        00->04->44->40      //begin=0;end=4;i=0~3;num=4
            [10 11 12 13 14]        01->14->43->30
            [20 21 22 23 24]        02->24->42->20
            [30 31 32 33 34]        03->34->41->10
            [40 41 42 43 44]
                                    11->13->33->31
                                    12->23->32->21      //begin=1;end=3;i=0~3;num=2
                                                        发现规律了吗TVT
        */
        int begin = 0, end = matrix.size()-1;
        int num = matrix.size()-1;
        while(begin<end)
        {
            for(int i=0;i<num;++i)
            {
                    int temp = matrix[end-i][begin];    //左下
                    matrix[end-i][begin] = matrix[end][end-i];    //左下=右下
                    matrix[end][end-i] = matrix[begin+i][end];    //右下=右上
                    matrix[begin+i][end] = matrix[begin][begin+i];      //右上=左上
                    matrix[begin][begin+i] = temp;        //左上=左下
            }
            ++begin;
            --end;
            num-=2;
        }
    }
};
```
