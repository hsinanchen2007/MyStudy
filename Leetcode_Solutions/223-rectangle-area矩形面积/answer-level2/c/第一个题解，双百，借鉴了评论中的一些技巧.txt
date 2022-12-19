
#define area1 ((C - A) * (D - B)) 
#define area2 ((G - E) * (H - F)) 

int compr(int *a, int *b)
{
    return *a - *b;
}

int GetOverLap(int x1, int x2, int x3, int x4)
{
    int arry[4] = {x1,x2,x3,x4};
    qsort(arry, 4, sizeof(int), compr);
    return arry[2] - arry[1]; // 中间两个是重叠的坐标
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H){
    int a1 = area1;
    int a2 = area2;
    // 不重叠处理
    if (G <= A || H <= B || E >= C || F >= D)
        return a1 + a2;
    // 计算重叠边长
    int xlen = GetOverLap(A, C, E, G);
    int ylen = GetOverLap(B, D, F, H);
    int a3 = xlen * ylen;
    a1 -= a3; // 防溢出
    return a1 + a2;
}