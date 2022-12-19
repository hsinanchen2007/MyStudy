
typedef struct {
    int* heapArr;           //二叉堆数据结构
    int tail;
    int k;
} KthLargest;

void Swap(int *a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/* 出二叉堆 */
void OutHeap(int* tail, int* heapArr){
    int ptrTemp;
    
    heapArr[0] = heapArr[(*tail)-1];
    ptrTemp = 0;
    while(2*ptrTemp+1 < (*tail)-1){
        if(2*ptrTemp+2 < (*tail)-1){
            if(heapArr[2*ptrTemp+2] > heapArr[ptrTemp] && heapArr[2*ptrTemp+1] > heapArr[ptrTemp]){
                break;
            }
            else if(heapArr[2*ptrTemp+1] < heapArr[2*ptrTemp+2]){
                Swap(&heapArr[2*ptrTemp+1], &heapArr[ptrTemp]);
                ptrTemp = 2*ptrTemp+1;
            }else{
                Swap(&heapArr[2*ptrTemp+2], &heapArr[ptrTemp]);
                ptrTemp = 2*ptrTemp+2;
            }
        }else{
            if(heapArr[2*ptrTemp+1] < heapArr[ptrTemp]){
                Swap(&heapArr[2*ptrTemp+1], &heapArr[ptrTemp]);
                ptrTemp = 2*ptrTemp+1;
            }else{
                break;
            }
        }
    }
    
    (*tail)--;
}

/* 入二叉堆 */
void InHeap(int* tail, int* heapArr, int element){
    int ptrTemp;
    
    heapArr[*tail] = element;
    ptrTemp = *tail;
    (*tail)++;
    while(ptrTemp > 0){
        if(heapArr[(ptrTemp - 1)/2] > heapArr[ptrTemp]){
            Swap(&heapArr[(ptrTemp - 1)/2], &heapArr[ptrTemp]);
        }
            
        ptrTemp = (ptrTemp - 1)/2;
    }
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* pNew = (KthLargest*)malloc(sizeof(KthLargest));
    pNew->heapArr = (int*)malloc(sizeof(int)*k);
    pNew->tail = 0;
    pNew->k = k;
    
    int loop;
    for(loop = 0;loop < numsSize;loop++){
        if(pNew->tail < k){
            InHeap(&(pNew->tail), pNew->heapArr, nums[loop]);
        }else{
            if(nums[loop] > pNew->heapArr[0]){
                OutHeap(&(pNew->tail), pNew->heapArr);
                InHeap(&(pNew->tail), pNew->heapArr, nums[loop]);
            }
        }
    }
    
    return pNew;
}

int kthLargestAdd(KthLargest* obj, int val) { 
    
    if(obj->tail < obj->k){
        InHeap(&(obj->tail), obj->heapArr, val);
    }else{
        if(val > obj->heapArr[0]){
            OutHeap(&(obj->tail), obj->heapArr);
            InHeap(&(obj->tail), obj->heapArr, val);
        }
    }
    
    return obj->heapArr[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heapArr);
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/