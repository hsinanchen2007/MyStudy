### 解题思路
1. dfs压缩，用flag表示column的选择情况
2. 发现第一行完成一半或过半的时候停止，偶数则halfcnt*2,奇数则过半前和过半后相加。

### 代码

```cpp
class Solution {
public:
    int cnt = 0;
    int half = 0;
    int halfcnt = 0;
    void nqueen(int n, int row, long long int flag,long long int ld, long long int rd, const long long int bitmask ){
        if(row == n){
            cnt++;
            return;
        }

        long long int avail = ~(flag|ld|rd) & bitmask;
        while(avail!=0){        
            long long int lowbit = avail&(-avail);
            if(row==0 && lowbit == half){
                halfcnt = cnt;
                if(n%2==0){
                    halfcnt *=2;
                    return;
                }
            }
            nqueen( n, row+1, flag|lowbit, (ld|lowbit)<<1, (rd|lowbit)>>1, bitmask);
            if(row==0 && lowbit == half){
                halfcnt += cnt;
                return;
            }
            avail = avail&(avail-1);
        }
        return;

    }
    int totalNQueens(int n) {
        if(n<=1){
            return 1;
        }
        half = 1<<(n/2 );
        
        vector<int> chess(n,0);
        long long int bitmask = (1<<n) -1;
        nqueen( n, 0, 0, 0, 0, bitmask);
        return halfcnt;
    }
};
```