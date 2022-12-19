### 解题思路
1、每一列砖块对应位置，因为给的输入是砖块宽度，所以需要对每一列做下累加处理
2、然后通过一个数组来统计对应砖块位置频度，要排除最后一块转
3、获取数组中最高频度max
4、用墙高度减去3得到的max即可

当前用例对墙的宽度最大是55000，所以MAP取到55001

### 代码

```c
#define MAX(a, b) ((a)>(b)?(a):(b))
#define MAXSIZE 55001

int leastBricks(int **wall, int wallSize, int *wallColSize)
{
    //把每一列对应的位置给出，就是从前往后累加
    for (int i = 0; i < wallSize; i++) {
        for (int j = 1; j < wallColSize[i]; j++) {
            wall[i][j] += wall[i][j - 1];
        }
    }

    int map[MAXSIZE] = {0};

    for (int i = 0; i < wallSize; i++) {
        for (int j = 0; j < wallColSize[i]-1; j++) {
            map[wall[i][j]]++;
        }
    }

    int max = 0;

    //统计出现平度最高的词个数，用wallsize去减
    for (int i = 0; i < MAXSIZE; i++) {
        max = MAX(max, map[i]);
    }

    return wallSize-max;
}
```