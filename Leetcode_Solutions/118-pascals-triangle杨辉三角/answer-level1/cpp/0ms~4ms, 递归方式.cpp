看题解给的是迭代，这里分享个递归方法，时间空间都还可以
```
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> curV;
        vector<int>         curRow;
        if(numRows == 0) return curV;
        
        _generate(numRows, curRow, curV);
        return curV;
    }
    void _generate( int numRows, 
                    vector<int> &curRow,
                    vector<vector<int>> &curV) {
        //递归结束条件
        if(numRows == 1) {
            curRow.insert(curRow.end(), 1);
            curV.insert(curV.end(), curRow);
            return;
        } 
        //递归得到numsRows-1行的数据
        _generate(numRows-1, curRow, curV);
        //将numsRows-1行的数据修改为numsRows行所需要数据
        //这里是内存空间内修改，从位置0改到位置numsRows-2
        for(int i=1; i<numRows-1; i++) {
            curRow[i-1] = curRow[i-1] + curRow[i];
        }
        //在当前行的最前面插入1,最后面也需要插1，但由于上述未修改到最后一个元素，所以不用插1
        curRow.insert(curRow.begin(), 1);
        curV.insert(curV.end(), curRow);
        return;
    }
};
```
