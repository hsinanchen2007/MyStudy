### 解题思路
此处撰写解题思路

### 代码

```c
/* 创建包含K个元素的最大堆 */
typedef struct {
    int numsSize;
    int *nums;
} KthLargest;

void shiftUp(int idx, int *nums, int numsSize)
{
    if (0 != idx) {
        int parIdx = (idx - 1) / 2;
        if (nums[idx] > nums[parIdx]) {
            int tmp = nums[idx];
            nums[idx] = nums[parIdx];
            nums[parIdx] = tmp;

            shiftUp(parIdx, nums, numsSize);
        }
    }
    return;
}

void shiftDown(int idx, int *nums, int numsSize)
{
    if (numsSize > idx * 2 + 2) {
        // double child
        int leftIdx = idx * 2 + 1, rightIdx = idx * 2 + 2, cldIdx = 0;
        if (nums[idx] < nums[leftIdx] || nums[idx] < nums[rightIdx]) {
            if (nums[leftIdx] > nums[rightIdx]) {
                cldIdx = leftIdx;
            } else {
                cldIdx = rightIdx;
            }

            int tmp = nums[cldIdx];
            nums[cldIdx] = nums[idx];
            nums[idx] = tmp;

            shiftDown(cldIdx, nums, numsSize);
        }
        return;
    } else if (numsSize == idx * 2 + 2) {
        // left child
        int leftIdx = idx * 2 + 1;
        if (nums[idx] < nums[leftIdx]) {
            int tmp = nums[leftIdx];
            nums[leftIdx] = nums[idx];
            nums[idx] = tmp;
        }
        return;
    } else {
        // no child
        return;
    }
}

KthLargest* kthLargestCreate(int* nums, int numsSize) {
    int *numsNew = calloc(numsSize, sizeof(int));
    if (NULL == numsNew) {
        return NULL;
    }

    KthLargest *head = calloc(1, sizeof(KthLargest));
    if (NULL == head) {
        free(numsNew);
        return NULL;
    }

    head->numsSize = numsSize;
    head->nums = numsNew;

    for (int loop = 0; loop < numsSize; loop++) {
        numsNew[loop] = nums[loop];
        shiftUp(loop, numsNew, loop + 1);
    }

    return head;
}

void kthLargestAdd(KthLargest* obj, int val) {
    
    obj->nums[obj->numsSize] = val;
    shiftUp(obj->numsSize, obj->nums, obj->numsSize+1);
    obj->numsSize += 1;
    
    return;
}

int kthLargestDel(KthLargest* obj) {
    
    int ret = obj->nums[0];

    obj->nums[0] = obj->nums[obj->numsSize - 1];
    obj->numsSize -= 1;
    shiftDown(0, obj->nums, obj->numsSize);
    
    return ret;
}

void kthLargestFree(KthLargest* obj) {
    free(obj->nums);
    free(obj);
    return;
}

int lastStoneWeight(int* stones, int stonesSize){
    int w1 = 0, w2 = 0, w = 0;
    KthLargest *obj = kthLargestCreate(stones, stonesSize);

    while (obj->numsSize > 1) {
        w1 = kthLargestDel(obj);
        w2 = kthLargestDel(obj);
        w = w1 - w2;
        if (w > 0) {
            kthLargestAdd(obj, w);
        }
    }

    if (1 == obj->numsSize) {
        w = kthLargestDel(obj);
    }

    kthLargestFree(obj);
    return w;
}
```