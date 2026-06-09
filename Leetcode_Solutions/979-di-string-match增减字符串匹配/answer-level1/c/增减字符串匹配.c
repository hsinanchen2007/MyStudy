```

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char * S, int* returnSize)
{
    int N = strlen(S);
    int a=N;
    int b=0;
    int *ret = (int *)malloc(sizeof(int)*(N+1));
    *returnSize = N + 1;
    for (int i=0;i<N;i++)
    {
        if (S[i] == 'I')
        {
            ret[i] = b;
            b++;
        }
        else
        {
            ret[i] = a;
            a--;
        }
    }
    ret[N] = b;
    return ret;
}

```
