typedef struct node{
    int number;
    int sum;
} NODE;


int cmp(const int* a, const int* b) {
    return (*a > *b) ? 1 : 0;
}

int mycmp(const void* p1, const void* p2) {
    return ((*(NODE *)p1).sum <= (*(NODE *)p2).sum) ? 1 : 0; 
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    int* result = NULL;
    NODE* temp = NULL; 
    int j = 0;

    result = (int*)calloc(k,sizeof(int));
    temp = (NODE*)calloc(1, sizeof(NODE));

    qsort(nums, numsSize, sizeof(int), cmp);
    temp->number = nums[0];
    temp->sum = 1;
    for(int i=0; i<numsSize-1; i++) {;
        if(nums[i] != nums[i+1]) {
            temp = (NODE*)realloc(temp, (j+2) * sizeof(NODE));
            j++;
            temp[j].number = nums[i+1];
            temp[j].sum = 1;
        } else {
            (temp[j].sum)++;
        }
    }

    qsort(temp, j+1, sizeof(NODE), mycmp);
    *returnSize = k;

    for(int j=0; j<k; j++) {
        result[j] = temp[j].number;
    }

    return result;
}