用数组模拟堆栈。性能和内存耗用应该都很少了。

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize){
    int *outArray = NULL;
    int i = 0;  //A[i], Input index
    int j = -1; //S[j], Stack index

    if ((asteroids == NULL) || (asteroidsSize == 0)) {
        printf("Warning: There has no star in array!\n");
        return NULL;
    }
    
    *returnSize = 0;
    outArray = (int*)malloc(asteroidsSize * sizeof(int));
    if (outArray == NULL) {
        return NULL;
    }
    
    while (i < asteroidsSize) {
        if ((j >= 0) && (outArray[j] > 0) && (asteroids[i] < 0)) {
            if (abs(asteroids[i]) == abs(outArray[j])) {
                //Pop
                j--;
            }
            else if (abs(asteroids[i]) > abs(outArray[j])) {
                //Pop, make collision
                j--;
                continue;
            }
        }
        else {
            //Push
            outArray[++j] = asteroids[i];
        }
        i++;
    }

    *returnSize = j + 1;
    return outArray;
}