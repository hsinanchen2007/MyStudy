一次qsort
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a,const void *b)
{
    int *ap = *(int **)a;       
    int *bp = *(int **)b;

    if(ap[1] == bp[1])
        return bp[0] - ap[0];
    else
        return bp[1] - ap[1];
}
int* filterRestaurants(int** restaurants, int restaurantsSize, int* restaurantsColSize, int veganFriendly, int maxPrice, int maxDistance, int* returnSize){
    if (restaurants == NULL || restaurantsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    qsort(restaurants, restaurantsSize, sizeof(int) * 2, cmp);
    int returnRestr[restaurantsSize];
    int num = 0;
    memset(returnRestr, 0, sizeof(int) * restaurantsSize);
    for (int i = 0; i < restaurantsSize; i++) {
        if (veganFriendly == 1) {
            if (restaurants[i][2] == 1 &&  restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance) {
                returnRestr[num] = restaurants[i][0];
                num++;
            } 
        } else {
            if (restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance) {
                returnRestr[num++] = restaurants[i][0];
            }
        }
    }
    *returnSize = num;
    int *arr = malloc(sizeof(int) * num);
    memset(arr, 0, sizeof(int) * num);
    for (int i = 0; i < num; i++) {
        arr[i] = returnRestr[i];
    }
    return arr;
}