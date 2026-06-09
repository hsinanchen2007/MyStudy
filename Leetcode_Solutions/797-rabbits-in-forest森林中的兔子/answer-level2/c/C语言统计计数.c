int numRabbits(int *a, int n)
{
    int map[1000] = {0};
    for (int i = 0; i < n; i++)
        map[a[i]] ++;

    int cnt = 0;
    for (int i = 0; i < 1000; i++) {
        if (map[i] == 0)
            continue;
        // 报数为i的个数有map[i]只兔子
        // 每i + 1只兔子报数为i则认定同一个颜色
        cnt += (map[i] + i) / (i + 1) * (i + 1);
    }

    return cnt;
}