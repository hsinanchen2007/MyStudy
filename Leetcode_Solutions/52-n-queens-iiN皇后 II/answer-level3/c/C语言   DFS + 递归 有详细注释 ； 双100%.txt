### 解题思路
1、用一维数组queenpos[]表示皇后放置的位置可以简化代码；
2、递归思路比较清晰。
### 代码

```c
int queenpos[20] = {-1};
int g_sum;
void step(int index, const int n) // 初始传入的index = 0； 表示放置第一个皇后
{
    // 1、 找到答案
    if (index == n) { // 递归到index = n-1, 表示已经成功放置了n个皇后
        g_sum++;
        return;
    }
    // 2、 边界问题
    // 3、 不用记录访问位置，无visited
    // 4、 广度：每一个step都要包含所有广度
    for (int i = 0; i < n; i++) { // 广度就是 0 ~ n-1位置(row)，可以放置第index个皇后。
        queenpos[index] = i; // 第index个皇后，可以尝试放在 0~n-1排； (列已经用数组下标index区分开)
        // 需要判断第index个皇后在i这个位置是否可以站稳, 如果可以站稳则执行第index+1个皇后的位置查找；
        if (index == 0) { // 第1个皇后肯定是OK的，不用校验有效性
            step(index + 1, n);
        } else {
            int tag = 0;
            // 其他的皇后需要考虑前面已经摆放的皇后的位置： 同ROW/同斜线， 如果冲突需要查找下一个位置；
            for (int j = 0; j < index; j++) {
                if (queenpos[j] == queenpos[index]) { // 检查前面的index -1 列，是否有和当前放的位置同一row
                    tag = 1;
                    break;
                }
                if (abs(index - j) == abs(i - queenpos[j])) { // 检查是否在同一个斜线
                    tag = 1;
                    break;
                }
            }
            // 不冲突，说明当前位置OK 则继续放下一个皇后。  ----> 这里一定不能放在上面的for ： else里边
            if (tag == 0)
                step(index + 1, n);
        }
    }
}

int totalNQueens(int n){
    g_sum = 0;
    if(n == 1) return 1;
    step(0, n);
    return g_sum;
}
```