与上一题n-queens类似，只是不需要保存结果，只要结果总数即可。那么可以用长度为n的数组存储棋盘，每个值表示当前列是否为皇后。
```
class Solution {
    bool isValid(vector<int> &v, int row, int col){
        bool valid=true;
        for(int i=0; valid && i<row; valid=v[i++]!=col);
        for(int i=row; valid && i--; valid=v[i]!=col+i-row);
        for(int i=row; valid && i--; valid=v[i]!=col+row-i);
        return valid;
    }
    int backtrack(vector<int> &v, int row){
        if(row==v.size()) return 1;
        int sum=0;
        for(int col=0; col<v.size(); ++col){
            v[row]=col;
            if(isValid(v,row,col)) sum+=backtrack(v,row+1);
            v[row]=-1;
        }
        return sum;
    }
public:
    int totalNQueens(int n) {
        vector<int> v(n,-1);
        return backtrack(v,0);
    }
};
```

![2019-06-20 10-32-03屏幕截图.png](https://pic.leetcode-cn.com/6186e115f0636f0f141facd5f4b89b37ccebaf8e62c02bdfd2ab307e9ddbaf3f-2019-06-20%2010-32-03%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)