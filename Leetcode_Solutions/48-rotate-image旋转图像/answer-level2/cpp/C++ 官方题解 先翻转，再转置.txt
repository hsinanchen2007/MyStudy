```
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {//先上下翻转，再按主对角线转置
        int m_size = matrix.size();
        for(int i=0;i<m_size/2;i++){
            for(int j=0;j<m_size;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[m_size-i-1][j];
                matrix[m_size-i-1][j] = tmp;
            }
        }
        for(int i=0;i<m_size;i++){
            for(int j=i+1;j<m_size;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        
    }
};
```

