typedef struct tagNUMR
{
    int id;
    int value;
    UT_hash_handle hh;
}NUMR_S;

int singleNumber(int* nums, int numsSize){
    int i;
    NUMR_S *numr = NULL;
    NUMR_S *tmp = NULL;
    NUMR_S *numht = NULL;

    for (i = 0; i < numsSize; i++) {
        HASH_FIND_INT(numht, &nums[i],numr);
        if (numr != NULL) {
            numr->value++;
            continue;
        }

        numr = (NUMR_S*)malloc(sizeof(NUMR_S));
        if (numr == NULL) {
            return 0;
        }
        numr->id = nums[i];
        numr->value = 1;

        HASH_ADD_INT(numht, id, numr);
    }

    for (numr = numht; numr != NULL; numr = numr->hh.next) {    
        if (numr->value == 1) {
            return numr->id;
        }
    }

    HASH_ITER(hh, numht, numr, tmp) {
        HASH_DEL(numht,numr);  
        free(numr);            
     }

    return 0;
}