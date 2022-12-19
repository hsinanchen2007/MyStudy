- 可以发现以下规律如果不考虑翻转那么假设是从右上作为对角线的第一个元素
- 那么对角线的起点是第一行的所有列以及其他行的最后一列，所以可以按这个
- 顺序遍历，同时设置一个计数器看遍历到第几条对角线方便翻转。
```cpp
class Solution {
public:
    int cnt=1,n,m;
    vector<int>res;
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        n = matrix.size();
        if(!n)return res;
        m = matrix[0].size();
        for(int j=0;j<m;++j)path(matrix,0,j);
        for(int i=1;i<n;++i)path(matrix,i,m-1);
        return res;
    }
    void path(vector<vector<int>>& matrix,int x,int y){
        vector<int>t;
        int i = x,j=y;
        while(i<n && j>=0){
            if(cnt&1) t.push_back(matrix[i][j]);
            else res.push_back(matrix[i][j]);
            ++i,--j;
        }
        if(cnt&1)for(int i=t.size()-1;i>=0;--i)res.push_back(t[i]);
        ++cnt;
    }
};
```