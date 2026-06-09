 - 改进官方题解一的方法，因为col,hill,dale这三个数组存的数，非0即1，
 - 可以考虑利用位运算改变比特位的0与1状态来代替数组，所以col,hill,dale没有必要弄成数组
 - 既能节省内存，又能快速运算，极限情况下一样可以0ms|100%
```
class Solution {
public:
    int totalNQueens(int n) {
        int count=0;
        backtrack(0,n,0,0,0,count);
        return count;
    }
    void backtrack(int r, int n, int col, int hill, int dale, int& count) {
        if (r>=n) count++;
        else  for(int c=0;c<n;c++)
                //检查col,hill,dale特定位上的值
                //如(1&col>>c)==0，就是检查col第c个比特位是否==0
                //r表示行下标，c表示列下标，r+c与r-c的值均为常数，注意：r-c有可能小于0，所以要+n
                if((1&col>>c)==0&&(1&hill>>r+c)==0&&(1&dale>>r-c+n)==0)
                    //将col,hill,dale特定位的0置为1
                    //如col|1<<c，就是将col第c个比特位的0变为1
                    //由于参数传的是右值，所以递归返回之后会自动回溯
                    backtrack(r+1,n,col|1<<c,hill|1<<r+c,dale|1<<r-c+n,count);
    }
};
```
