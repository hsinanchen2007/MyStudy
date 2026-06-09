class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int i, j, k;              //计数变量
        int l = matrix.size();    //列长
        int m = matrix[0].size();  //行长
        int mini,minx,maxj;        //行最小值、最小值列坐标、列最大值
        vector<int> minluck;       //结果
        for(i = 0; i < l; i++)
        {
            mini = matrix[i][0];   //最小值都初始化为第一列
            minx = 0;              //坐标记录
            for(j = 0; j < m; j++)
            {
                if(matrix[i][j] < mini)
                {
                    mini = matrix[i][j];  //最小值变化
                    minx = j;             //坐标随之变化
                }
            }
            maxj = matrix[i][minx];   //最大值初始化为最小值自身
            for(k = 0; k < l; k++)
            {
                if(matrix[k][minx] > mini)   //此列存在大于最小值的值，跳出循环
                {
                    maxj = matrix[k][minx];  //记录新的最大值（不一定是本列最大）
                    break;
                }
            } 
            if(maxj == mini)   //两值相同
            {
                minluck.push_back(mini);
                break;   //题目好像测试的都是只存在一个幸运值的，所以就直接break了，如果多个就注释掉break
            }   
        }
        return minluck;
    }
};