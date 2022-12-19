void compare(int* asteroids, int *posIn, int *posOut, int asteroidsSize){
    int sum = 0;

    if ((asteroids[*posOut] > 0) && (asteroids[*posIn] < 0)){
        sum = asteroids[*posOut] + asteroids[*posIn];
        if (sum == 0){
            if (*posOut <= 0 && (++(*posIn) < asteroidsSize)){
                asteroids[*posOut] = asteroids[*posIn];
            }
            else {
                (*posOut)--; 
            }
        }
        else if (sum < 0){
            if (*posOut > 0){
                (*posOut)--;
                compare(asteroids, posIn, posOut, asteroidsSize);
            }
            else {
                asteroids[*posOut] = asteroids[*posIn];
            }
        }
    }
    else {
        asteroids[++(*posOut)] = asteroids[*posIn];
    }
    return;
}

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize){
    int i = 0;
    *returnSize = 0;

    if (asteroids == NULL){
        return NULL;
    }

    for (i=1; i<asteroidsSize; i++){
        compare(asteroids, &i, returnSize, asteroidsSize);
    }
    (*returnSize)++;
    return asteroids;
}