```
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //初始化结果矩阵
        //循环由外向内填充 一圈一圈 
        // 按照上行 右列 下行 左列填
        vector<vector<int>> res(n, vector<int>(n,0));
        int begin = 1;
        for(int index=0; index<=n/2; ++index){
            feed(res, n, begin, index);
        }
        return res;
    }
private:
    void feed(vector<vector<int>>& res, int n, int& begin, int index){
        for(int i=index; i<n-index; ++i){//填充上行
            res[index][i] = begin++;
        }

        if(begin > n*n) return;//n为奇数 最里面一圈只有一个数

        for(int i=index+1; i<n-1-index; ++i){//填充右列 不含上下（已在行填充完成
            res[i][n-1-index] = begin++;
        }
        for(int i=n-1-index; i>=index; --i){//填充下行
            res[n-1-index][i] = begin++;
        }
        for(int i=n-2-index; i>index; --i){//填充左列 不含上下
            res[i][index] = begin++;
        }
    }
};
```
