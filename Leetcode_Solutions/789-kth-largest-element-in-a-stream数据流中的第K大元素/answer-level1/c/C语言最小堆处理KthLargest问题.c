```
typedef struct {
    int *heap; // 最小堆
    int size; // 堆的元素个数
    int k; // 记录堆内存空间大小
} KthLargest;


KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest *KL = (KthLargest *)malloc(sizeof(KthLargest));// 初始化堆
    int cnt = 0;
    int temp, ppos, lpos, rpos, mpos, ipos;

    KL->heap = (int *)malloc(k * sizeof(int)); // 给堆分配存储空间
    KL->size = 0;
    KL->k = k;

    while (KL->size < k && cnt < numsSize) { // 向堆空间中添加元素

        KL->heap[cnt] = nums[cnt];
        ipos = KL->size; // 当前插入元素位置
        ppos = (ipos - 1) / 2; // KL->heap[ipos]父元素的位置

        while (ipos > 0 && KL->heap[ipos] < KL->heap[ppos]) { // 最小堆化

            temp = KL->heap[ppos];
            KL->heap[ppos] = KL->heap[ipos];
            KL->heap[ipos] = temp;

            ipos = ppos;
            ppos = (ipos - 1) / 2;
        }

        cnt++;
        KL->size++;
    }

    if (cnt < numsSize) { // 若nums还有剩余元素 
        for (int i = cnt; i < numsSize; i++) { // 将剩余元素挨个儿与堆顶元素比较

            if (nums[i] > KL->heap[0]) { // 若大于堆顶元素，堆顶元素置换

                KL->heap[0] = nums[i];
                ipos = 0;

                while(1) { // 重新最小堆化

                    lpos = ipos * 2 + 1; // KL->heap[ipos] left child的位置
                    rpos = ipos * 2 + 2; // KL->heap[ipos] right child的位置

                    if (lpos < KL->size && KL->heap[ipos] > KL->heap[lpos]) {
                        mpos = lpos;
                    }
                    else {
                        mpos = ipos;
                    }

                    if (rpos < KL->size && KL->heap[mpos] > KL->heap[rpos]) {
                        mpos = rpos;
                    }
                    
                    if (ipos == mpos) {
                        break;
                    } 
                    else {
                        temp = KL->heap[ipos];
                        KL->heap[ipos] = KL->heap[mpos];
                        KL->heap[mpos] = temp;

                        ipos = mpos;
                    }
                }
            }
        }
    }

    return KL;
}

int kthLargestAdd(KthLargest* obj, int val) {
    int ppos, lpos, rpos, mpos, ipos, temp;
    if (obj->size < obj->k) { // 最小堆空间没有满

        obj->heap[obj->size] = val; // 堆底插入元素
        ipos = obj->size;
        ppos = (ipos - 1) / 2;

        while (ipos > 0 && obj->heap[ppos] > obj->heap[ipos]) { // 最小堆化

            temp = obj->heap[ppos];
            obj->heap[ppos] = obj->heap[ipos];
            obj->heap[ipos] = temp;

            ipos = ppos;
            ppos = (ipos - 1) / 2;

        }
        obj->size++;
    }
    else if (val > obj->heap[0] && obj->size == obj->k) { // 当堆已满，新加入的元素与堆顶元素比较
        obj->heap[0] = val;
        ipos = 0;
        
        while (1) {
            lpos = ipos * 2 + 1;
            rpos = ipos * 2 + 2;
            if (lpos < obj->size && obj->heap[ipos] > obj->heap[lpos]) {
                mpos = lpos;
            }
            else {
                mpos = ipos;
            }

            if (rpos < obj->size && obj->heap[mpos] > obj->heap[rpos]) {
                mpos = rpos;
            }

            if (ipos == mpos) {
                break;
            }
            else {
                temp = obj->heap[ipos];
                obj->heap[ipos] = obj->heap[mpos];
                obj->heap[mpos] = temp;

                ipos = mpos;
            }
        }
    }
    return obj->heap[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/
```
