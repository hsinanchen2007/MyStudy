执行用时 24 ms 100.00% 
内存消耗 9.4 MB 100.00%

遍历每一行，找出最小值；
根据该最小值比较对应的列上的数，判断是否是最大值
若是，则存入vector中

```
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;

        for(int i=0;i<matrix.size();i++){
            int min = matrix[i][0];
            int index = 0;

            //找出一行中最小的数，保存数值与列下标
            for(int j=1;j<matrix[i].size();j++){
                if(matrix[i][j]<min){
                    min = matrix[i][j];
                    index = j;
                }
            }

            //判断数是否是该列的最大值
            int flag = 1;
            for(int m=0;m<matrix.size();m++){
                if(matrix[m][index]>min){
                    flag = 0;
                    break;
                }
            }
            if(flag)    res.push_back(min);
        }

        return res;
    }
};
```

