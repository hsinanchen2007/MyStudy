```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numMovesStones(int a, int b, int c, int* returnSize){
    *returnSize = 2;
    int *res = (int*)calloc(*returnSize, sizeof(int));
    int t;
    if(a > b){
        t = a;
        a = b;
        b = t;
    }
    if(a > c){
        t = a;
        a = c;
        c = t;
    }
    if(b > c){
        t = b;
        b = c;
        c = t;
    }
    if (a + 1 == b && b + 1 == c)
        return res;
    else if (a + 1 == b || b + 1 == c){
        res[0] = 1;
        if (a + 1 != b)
            res[1] = b - a - 1;
        else
            res[1] = c - b - 1;
    } 
    else if (a + 2 == b || b + 2 == c){
        res[0] = 1;
        res[1] = (b - a - 1) + (c - b - 1);
    }
    else{
        res[0] = 2;
        res[1] = (b - a - 1) + (c - b - 1);
    }
    return res;
}
```
