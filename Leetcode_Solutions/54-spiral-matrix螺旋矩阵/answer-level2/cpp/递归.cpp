思路就是从外向里转圈圈进去直至结束
```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        spiral(res, matrix);
        return res;
    }
private:
    void spiral(vector<int> & res, vector<vector<int>>& matrix){
        
        if(matrix.empty() || matrix[0].empty()) return;//matrix 为空后返回 
        //同时检查从下往上插入后matrix中每一行是否已为空 为空同样返回  
        //注意先检查m空 再检查m[0]空  防止输入就是[] 报错
        
        res.insert(res.end(), matrix[0].begin(), matrix[0].end());//第一行顺序插入
        matrix.erase(matrix.begin());//每次插入res后删除matrix

        if(matrix.empty()) return;//每次删除后都要检查是否已空

        for(int i=0; i<matrix.size()-1; ++i){//从上到下插入matrix最后一列元素（没有最后一个数
            res.push_back(matrix[i].back());
            matrix[i].pop_back();
        }
        
        if(matrix.empty()) return;

        res.insert(res.end(), matrix.back().rbegin(), matrix.back().rend());//逆序插入最后一行 
        matrix.pop_back();
        
        if(matrix[0].empty() || matrix.empty()) return;//一行元素为空后是[] matrix 并不为空

        for(int i=matrix.size()-1; i>=0; --i){//从下到上插入第一列元素
            res.push_back(matrix[i][0]);
            matrix[i].erase(matrix[i].begin());
        }
        
        spiral(res, matrix);//递归
    }
};
```
