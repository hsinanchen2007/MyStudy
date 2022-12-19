### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int core(int row, int rows,int col, int cols,int k, vector<bool>&visited){
        int count=0;
        if(check( row,  rows,  col, cols, k, visited)){
            visited[row*cols + col] = true;
            
            count = 1 + core(row-1, rows, col, cols,k, visited)
                    +   core(row+1,rows,col,cols,k,visited)
                    +   core(row,rows,col-1,cols,k,visited)
                    +   core(row,rows,col+1,cols,k,visited);
        }
        return count;
    }

    bool check(int row, int rows, int col,int cols,int k,vector<bool>&visited){
        if(row>=0 && row<rows && col>=0 && col<cols && visited[row*cols+col] == false && checkcore(row) + checkcore(col) <= k){
            return true;
        }
        return false;
    }

    int  checkcore(int num){
        int sum=0;
        while(num>0){
            sum+=num%10;
            num = num/10;
        }
        return sum;
    }


    int movingCount(int m, int n, int k) {
        vector<bool>visited (m*n, false);
        int count = core(0,m,0,n,k,visited);
        return count;
    }

};
```