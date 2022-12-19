int cmpfunc (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int lastStoneWeight(int* stones, int stonesSize){
    int i = 0;
    while(stonesSize-i>1){
        qsort(stones,stonesSize-i, sizeof(int),cmpfunc);
        if(stones[stonesSize-1-i]>=stones[stonesSize-2-i])
        {
            stones[stonesSize-2-i] = stones[stonesSize-1-i] - stones[stonesSize-2-i];
            stones[stonesSize-1-i] = 0;
        }
        i++;
    }
        return stones[0];
}