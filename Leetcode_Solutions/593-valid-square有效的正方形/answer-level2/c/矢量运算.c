### 解题思路
使用矢量长度计算边长，矢量乘法计算直角
时间和内存均击败100%

### 代码

```c

int int_cmp(const void * a, const void * b)
{
    const int * x = (int *)a;
    const int * y = (int *)b;

    if (*x == *y)
    {
        return 0;
    }
    else if (*x > *y)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size){
    int pos[8] = {0};
    int edge[4] = {0};
    int vec[4][2] = {0};
    int tmp = 0;

    pos[0] = p1[0];
    pos[1] = p1[1];
    pos[2] = p2[0];
    pos[3] = p2[1];
    pos[4] = p3[0];
    pos[5] = p3[1];
    pos[6] = p4[0];
    pos[7] = p4[1];

    qsort(pos, 4, 2*sizeof(int), int_cmp);

    if ((pos[0] == pos[2]) && (pos[1] > pos[3]))
    {
        tmp = pos[1];
        pos[1] = pos[3];
        pos[3] = tmp;
    }

    if ((pos[4] == pos[6]) && (pos[5] > pos[7]))
    {
        tmp = pos[5];
        pos[5] = pos[7];
        pos[7] = tmp;
    }

    vec[0][0] = pos[2] - pos[0]; 
    vec[0][1] = pos[3] - pos[1]; 
    vec[1][0] = pos[4] - pos[0]; 
    vec[1][1] = pos[5] - pos[1];
    vec[2][0] = pos[2] - pos[6]; 
    vec[2][1] = pos[3] - pos[7];
    vec[3][0] = pos[4] - pos[6]; 
    vec[3][1] = pos[5] - pos[7];

    edge[0] = vec[0][0]*vec[0][0] + vec[0][1]*vec[0][1];
    edge[1] = vec[1][0]*vec[1][0] + vec[1][1]*vec[1][1];
    edge[2] = vec[2][0]*vec[2][0] + vec[2][1]*vec[2][1];
    edge[3] = vec[3][0]*vec[3][0] + vec[3][1]*vec[3][1];

    if (edge[0] && (edge[0] == edge[1]) && (edge[1] == edge[2]) && (edge[2] == edge[3])
        && (0 == vec[0][0]*vec[1][0]+vec[0][1]*vec[1][1]) 
        && (0 == vec[2][0]*vec[3][0]+vec[2][1]*vec[3][1]))
    {
        return true;
    }

    return false;
}
```