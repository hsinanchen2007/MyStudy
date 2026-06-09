### 解题思路
回溯法

### 代码

```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<bool> flagCol(n,false);
        vector<vector<bool> > flag(m,flagCol);

        return getArriveNum(0,0,m,n,k,flag);
    }

    int getArriveNum(int row,int col,int &m,int &n,int &k,vector<vector<bool> >& flag){
        if(row < 0 || col < 0 || row >= m || col >= n){
            return 0;
        }
        if(flag[row][col]){
            return 0;
        }

        if(getSum(row,col) <= k){
            flag[row][col] = true;
            return 1 + getArriveNum(row+1,col,m,n,k,flag) + getArriveNum(row,col+1,m,n,k,flag) + getArriveNum(row-1,col,m,n,k,flag) + getArriveNum(row,col-1,m,n,k,flag);
        }
        return 0;
    }

    // 获得坐标的和
    int getSum(int row,int col){
        int sum = 0;
        while(row != 0 || col != 0){
            sum += (row % 10 + col % 10);
            row = row / 10;
            col = col / 10;
        }
        return sum;
    }
};
```