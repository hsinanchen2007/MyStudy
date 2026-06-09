思路见注释，简单说就是遍历加判断是否可达，
时间复杂度O(n2)，空间复杂度O(n2)
还有一种比较容易想到的思路就是递归
```C++
class Solution {
public:
    // 获取行坐标和列坐标的数位和
    int getSum(int x, int y){
        int total = 0;
        while(x != 0){
            total += x%10;
            x /= 10;
        }
        while(y != 0){
            total += y%10;
            y /= 10;
        }
        return total;
    }
    int movingCount(int m, int n, int k) {
        // 标记数组，判断是否可达，可达为1。行列+2防越界
        vector<vector<int>> mark(m+2,vector<int>(n+2));
        // [0,0]坐标肯定可达，对应标记数组为mark[1][1]
        mark[1][1] = 1;
        int count = 1;
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if( mark[i-1][j] == 1|| mark[i][j-1] == 1 ||
                    mark[i+1][j] == 1 || mark[i][j+1] == 1 ){
                    if(getSum(i-1,j-1) <= k){
                        count++;
                        //cout<<i-1<<" "<<j-1<<endl;
                        mark[i][j] = 1;
                    }
                }
            }
        }
        return count;
    }
};
```
