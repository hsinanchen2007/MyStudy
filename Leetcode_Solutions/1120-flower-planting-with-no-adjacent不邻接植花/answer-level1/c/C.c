160ms(100%) 18.9MB(100%)

先遍历每条路径，根据路径的起始点得出每个花园所临近的0-3个其他的花园，对于标号为i的花园map[i]是一个数组，含有三个元素，元素的值代表花园的标号，0代表无花园。
再遍历每一个花园，根据标号为i的花园的花种与map[i]数组内的三个花园的花种均不相同，得出result。

小白，写的糙，望见谅

int* gardenNoAdj(int N, int** paths, int pathsSize, int* pathsColSize, int* returnSize)
{
    int *result = (int *)calloc(N , sizeof(int));
    int i, j, r, m;
    int (*map)[3] = calloc(3 * N, sizeof(int)); //标号i的花园对应的临近花园
    int *order = calloc(N, sizeof(int)); //标记下一个临近花园插入数组map[i]的位置
    
    result[0] = 1; //先给1号花园种1号花
    if(N == 1)    //只有一个花园
    {   
        *returnSize = N;
        return result;
    }
    for(i = 0; i < pathsSize; i++) //建立map[i]
    {
        map[paths[i][0] - 1][order[paths[i][0] - 1]++] = paths[i][1];
        map[paths[i][1] - 1][order[paths[i][1] - 1]++] = paths[i][0];
    }
    for(i = 0; i < N; i++) //找到与临近花园花种不同的花
    {
        if(map[i][0] == 0) // map[i][0]等于0代表i号花园没有临近的花园，直接种1号花
        {         
            result[i] = 1;
            continue;
        }
        for(r = 1; r < 5; r++) //从1-4尝试各个花种直到与其他临近花园的花种都不同
        {
            for(j = 0, m = 0; j < 3; j++)
            {
                if(map[i][j] == 0)
                    m++;
                else if(result[map[i][j] - 1] != r)
                    m++;
            }
            if(m == 3)
            {
                result[i] = r;
                break;
            }
        }
    }
    
    *returnSize = N;
    return result;
}