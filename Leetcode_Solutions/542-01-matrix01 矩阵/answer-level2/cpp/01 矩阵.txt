### 算法分析
1. 使用广度优先搜索，定义队列que用于存储待遍历的节点<i,j>，定义二维数组result用于存储结果并初始化为0
2. 遍历matrix，i = 0 : matrix.size()-1, j = 0 : matrix[i].size()-1
3. 如果matrix[i][j]==0，将<i,j>入队
4. 否则result[i][j]赋值为IntMax
5. 遍历队列直到为空，出队队首元素<i,j>
6. 遍历<i,j>的四周元素<next_i,next_j>，如果result<new_i,next_j> > result<i,j> + 1
   ，则result<next_i,next_j> =  result<i,j> + 1，并将<next_i,next_>入队
7. 最后返回result
### 复杂度分析
+ 时间复杂度：O(n), n=i*j
+ 空间复杂度：O(n)，队列使用的空间
### 源码
```C++ []
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rowCount = matrix.size();
        if (rowCount == 0)
            return matrix;

        int colCount = matrix[0].size();        
        vector<vector<int>> result(rowCount, vector<int>(colCount, 0));
        queue<pair<int,int>> que;

        for (int i = 0; i < rowCount; i++)
        {
            for (int j = 0; j < colCount; j++)
            {
                if (matrix[i][j] == 0)
                {
                    que.push(make_pair(i, j));
                }
                else
                {
                    result[i][j] = INT_MAX;
                }
            }            
        }

        int diff[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!que.empty())
        {
            pair<int,int> pos = que.front();
            int i = pos.first;
            int j = pos.second;
            que.pop();

            for (int index = 0; index < 4; index++)
            {
                int diff_i = diff[index][0];
                int diff_j = diff[index][1];
                int new_i = i + diff_i;
                int new_j = j + diff_j;

                if (new_i >= 0 && new_i < rowCount && new_j >= 0 && new_j < colCount
                    && result[new_i][new_j] > result[i][j] + 1)
                {
                    result[new_i][new_j] = result[i][j] + 1;
                    que.push(make_pair(new_i, new_j));
                }
            }
        }   

        return result;     
    }
};