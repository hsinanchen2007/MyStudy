### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   long upperlim =1;
    int res=0;
    public int totalNQueens(int n) {
        upperlim = (upperlim << n) - 1;
        test(0,0,0);
        return res;
    }
    // row表示下一行皇后不能放置的位置(这个位置与上一个皇后同一列)
    // ld表示下一行皇后不能放在位置(这个位置与上一行皇后成左对角线)
    // rd表示下一行皇后不能放在位置(这个位置与上一行皇后成右对角线)
    
    private void test(long row, long ld, long rd)
    {
        if (row != upperlim)
        {
            long pos = upperlim & ~(row | ld | rd);
            while (pos!=0)    // 0 -- 皇后没有地方可放，回溯
            {
                long p = pos & -pos;
                pos -= p;
                test(row + p, (ld + p) << 1, (rd + p) >> 1);
            }
        }
        else
        {
            // row的所有位都为1，即找到了一个成功的布局，回溯
            res++;
        }
        return;
    }
}
```