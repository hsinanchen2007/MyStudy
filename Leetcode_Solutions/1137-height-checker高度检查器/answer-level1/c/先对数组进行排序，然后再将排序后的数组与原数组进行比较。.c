
int heightChecker(int* heights, int heightsSize){

    int returnSize=0, tmp=0;
    int *ta = (int *)malloc(sizeof(int)*heightsSize + 1);
    memset(ta, 0, sizeof(int)*heightsSize + 1);
    memcpy(ta, heights, sizeof(int)*heightsSize);

    for(int i=0; i<heightsSize; i++){
        for(int j=i+1; j<heightsSize; j++){
            if(ta[i] > ta[j]){
                tmp = ta[i];
                ta[i] = ta[j];
                ta[j] = tmp;
            }
        }
    }

    for(int i=0; i<heightsSize; i++){
        if(ta[i] != heights[i]){
            returnSize++;
        }
    }

    return returnSize;
}
