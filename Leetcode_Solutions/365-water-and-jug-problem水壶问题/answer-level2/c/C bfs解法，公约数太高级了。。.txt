### 解题思路
借鉴评论大神的解法，复现了下自己的理解。

### 代码

```c
#define MAX 1000000

int g_flag[MAX];
bool BFS(int x, int y, int z, int left)
{   //x为大杯水，y为小杯 
    //left为某状态下一个杯中的存水量，left<=x恒成立
    if (left < 0 || g_flag[left] == 1) return false;

    if (left == z || (left + x) == z || (left + y) == z || (x - (y - left)) == z || (y - (x - left)) == z)
        return true;
    
    g_flag[left] = 1; //通过大数组标记错误的left状态，比较耗内存
    //BFS遍历下一步可能出现的存水量
    if (left <= y) return BFS(x, y, z, x - (y - left)) || BFS(x, y, z, y - (x - left));
    else return BFS(x, y, z, left - y) || BFS(x, y, z, y - (x - left));
    //return BFS(x, y, z, abs(x - left)) || BFS(x, y, z, abs(y - left));
}

bool canMeasureWater(int x, int y, int z){
    if (x + y < z) {
        return false;
    }
    if (z == 0) return true;

    memset(g_flag, 0, sizeof(g_flag));
    if (x < y) { // 使x为大杯
        int tmp = y;
        y = x;
        x = tmp;
    }
    return BFS(x, y, z, 0); //空杯开始
}
```