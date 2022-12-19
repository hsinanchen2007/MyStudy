```
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize){
    if (asteroidsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int *res = (int *)malloc(sizeof(int) * asteroidsSize);
    *returnSize = 0;

    for (int i = 0;i < asteroidsSize;) {
       // printf("%d %d %d\n", *returnSize, i,  asteroids[i]);
        if (*returnSize == 0) {
            res[*returnSize] = asteroids[i];
            (*returnSize)++;
            i++;
            continue;
        }

        if (asteroids[i] > 0 || (asteroids[i] < 0 && res[(*returnSize) - 1] < 0)) {
            res[*returnSize] = asteroids[i];
            (*returnSize)++;
        } else if (res[(*returnSize) - 1] > 0) {
            if (abs(asteroids[i]) == abs(res[(*returnSize) - 1])) {
                res[(*returnSize) - 1] == 0;
                (*returnSize)--;
            } else if (abs(asteroids[i]) > abs(res[(*returnSize) - 1])){
                res[(*returnSize) - 1] == 0;
                (*returnSize)--;
                continue;
            }
        }
        i++;
    }
    return res;
}

```
