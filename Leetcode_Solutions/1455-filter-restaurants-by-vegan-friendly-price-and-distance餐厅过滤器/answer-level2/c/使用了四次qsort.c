```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int CompareVeganFriendly(const void * elem1,const void * elem2){
    int* e1 = *((uintptr_t*)elem1);
    int* e2 = *((uintptr_t*)elem2);
    if(e1[2] < e2[2]) {
        return 1;
    }

    return -1;
}

int CompareMaxPrice(const void * elem1,const void * elem2){
    int* e1 = *((uintptr_t*)elem1);
    int* e2 = *((uintptr_t*)elem2);
    if(e1[3] > e2[3]) {
        return 1;
    }

    return -1;
}

int CompareMaxDistance(const void * elem1,const void * elem2){
    int* e1 = *((uintptr_t*)elem1);
    int* e2 = *((uintptr_t*)elem2);
    if(e1[4] > e2[4]) {
        return 1;
    }

    return -1;
}

int CompareRating(const void * elem1,const void * elem2){
    int* e1 = *((uintptr_t*)elem1);
    int* e2 = *((uintptr_t*)elem2);
    if(e1[1] < e2[1]) {
        return 1;
    }
    if(e1[1] == e2[1] && e1[0] < e2[0]) {
        return 1;
    }

    return -1;
}

int* filterRestaurants(int** restaurants, int restaurantsSize, int* restaurantsColSize, int veganFriendly, int maxPrice, int maxDistance, int* returnSize){
    int count2 = 0;
    if(veganFriendly == 1) {
        qsort((void*)restaurants, restaurantsSize, sizeof(int*), CompareVeganFriendly);
        for(; count2 < restaurantsSize; count2 ++) {
            if(restaurants[count2][2] != veganFriendly) {
                break;
            }
        }
    }
    else {
        count2 = restaurantsSize;
    }

    qsort((void*)restaurants, count2, sizeof(int*), CompareMaxPrice);
    int count3 = 0;
    for(; count3 < count2; count3 ++) {
        if(restaurants[count3][3] > maxPrice) {
            break;
        }
    }

    qsort((void*)restaurants, count3, sizeof(int*), CompareMaxDistance);
    int count4 = 0;
    for(; count4 < count3; count4 ++) {
        if(restaurants[count4][4] > maxDistance) {
            break;
        }
    }

    qsort((void*)restaurants, count4, sizeof(int*), CompareRating);
    int *ans = (int*)malloc(count4 * sizeof(int));
    if(ans == NULL) {
        return NULL;
    }
    *returnSize = count4;

    for(int count1 = 0; count1 < count4; count1 ++) {
        ans[count1] = restaurants[count1][0];
    }

    return ans;
}

```
