#define MAXNUM 1000

int g_result[MAXNUM] = {0};

int GetResult(int n)
{
    if (g_result[n] != 0) {
        return g_result[n];
    }
    g_result[n] = GetResult(n - 1) + GetResult(n - 2);
    return g_result[n];
}

int climbStairs(int n){
    g_result[0] = g_result[1] = 1;

    return GetResult(n);
}