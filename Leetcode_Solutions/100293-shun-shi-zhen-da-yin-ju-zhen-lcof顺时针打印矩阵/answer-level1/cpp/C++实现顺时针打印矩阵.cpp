### 解题思路
按圈打印，写成循环。
注意打印每一行的判断，不仅是判断起点，终点，还要判断是否存在打印行列的条件

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> s;//用来记录打出的数字
        if(matrix.size()==0 || matrix[0].size()==0) return s;
        //if(matrix.empty()) return s;
        int row=matrix.size();//行
        int col=matrix[0].size();//列
        int start=0;
        while(start*2<row&&start*2<col)//可以打几个环
        {
            s=printmatrix(start,row,col,s,matrix);//start表示环的起点
            start=start+1;
        }
        return s;
    }

    vector<int> printmatrix(int start,int row,int col,vector<int> s,vector<vector<int>> matrix)
    //打印函数，start表示环起点，row表示几排，col表示几行
    {
        for(int i=start;i<col-start;i++)//打印行
        {
            s.push_back(matrix[start][i]);
        }

        if(start+1<=row-start-1){//
        for(int j=start+1;j<row-start;j++)//打印列
        {
            s.push_back(matrix[j][col-start-1]);
        }}

        if(col-start-2>=start &&start+1<=row-start-1){
        for(int i=col-start-2;i>=start;i--)//打印行
        {
            s.push_back(matrix[row-start-1][i]);
        }}

        if(row-start-2>=start-1 &&col-start-2>=start){
        for(int j=row-start-2;j>start;j--)//打印列
        {
            s.push_back(matrix[j][start]);
        }}
        return s;
    }
};
```