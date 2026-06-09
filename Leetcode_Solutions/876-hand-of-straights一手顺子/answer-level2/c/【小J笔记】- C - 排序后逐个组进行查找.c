```
#define TRUE (1)
#define FALSE (0)
#define MAX_SIZE (10010)

int g_visit[MAX_SIZE];

int CmpFunc(const void *a, const void *b)
{
    return (*(int*)a) - (*(int*)b);
}

bool isNStraightHand(int* hand, int handSize, int W)
{
    int i;
    int j;
    int k;
    int flag;    
    int start;
    int end;
    if (handSize % W != 0) {
        return FALSE;
    }
    qsort(hand, handSize, sizeof(int), CmpFunc);    
    for (i = 0; i < handSize; i++) {
        g_visit[i] = FALSE;
    }
    for (i = 0; i < handSize; i++) {
        if (g_visit[i] == FALSE) {            
            start = hand[i];
            end = start + W - 1;
            for (j = start; j <= end; j++) {
                flag = FALSE;
                for (k = i; k < handSize; k++) {
                    if ((g_visit[k] == FALSE) && (hand[k] == j)) {
                        g_visit[k] = TRUE;
                        flag = TRUE;
                        break;
                    }
                    if (hand[k] > j) {
                        break;
                    }
                }
                if (flag == FALSE) {
                    return FALSE;
                }
            }
        }
    }   
    return TRUE;
}
```
