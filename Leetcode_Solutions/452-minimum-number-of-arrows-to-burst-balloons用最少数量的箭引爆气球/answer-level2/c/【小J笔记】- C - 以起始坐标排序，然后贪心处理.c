```
#define MAX_SIZE (10010)
#define TRUE (1)
#define FALSE (0)
#define NULL_PTR (0)

int g_visit[MAX_SIZE];

int CmpFunc(const void *a, const void *b)
{
    int *ca = (*(int**)a);
    int *cb = (*(int**)b);
    return (ca[1] - cb[1]);    
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize)
{
    int i;
    int j;    
    int end;
    int numArrow = 0;
    if ((points == NULL_PTR) || (pointsColSize == NULL_PTR)) {
        return numArrow;
    }
    qsort(points, pointsSize, sizeof(points[0]), CmpFunc);
    for (i = 0; i < pointsSize; i++) {        
        g_visit[i] = FALSE;
    }
    for (i = 0; i < pointsSize; i++) {
        if (g_visit[i] == FALSE) {
            g_visit[i] = TRUE;
            numArrow++;
            end = points[i][1];
            for (j = i + 1; j < pointsSize; j++) {
                if (points[j][0] <= end) {   
                    if (g_visit[j] == FALSE)  {
                        g_visit[j] = TRUE;
                    }                                 
                } else {
                    break;
                }
            }
        }                
    }
    return numArrow;
}
```
