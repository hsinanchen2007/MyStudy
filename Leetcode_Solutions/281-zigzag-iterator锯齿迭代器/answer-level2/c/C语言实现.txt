### 解题思路
结构体里面用一个新数组装值。

### 代码

```c
struct ZigzagIterator {
    int ptr;
    int maxLen;
    int* nums;
};

struct ZigzagIterator *zigzagIteratorCreate(int* v1, int v1Size, int* v2, int v2Size) {
    struct ZigzagIterator* iter = (struct ZigzagIterator*)malloc(sizeof(struct ZigzagIterator));
    int maxLen = v1Size + v2Size;
    iter->maxLen = maxLen;
    iter->ptr = 0;
    iter->nums = (int*)malloc(maxLen*sizeof(int));
    int index = 0;
    int maxSize = fmax(v1Size, v2Size);
    for (int i = 0; i < maxSize; i++) {
        if (i < v1Size) {
            iter->nums[index] = v1[i];
            index++;
        }
        if (i < v2Size) {
            iter->nums[index] = v2[i];
            index++;
        }
    }
    return iter;
}

bool zigzagIteratorHasNext(struct ZigzagIterator *iter) {
    if (iter->ptr >= iter->maxLen) {
        return false;
    }
    return true;
}

int zigzagIteratorNext(struct ZigzagIterator *iter) {
    int n = (iter->nums)[iter->ptr];
    iter->ptr++;
    return n;
}

/** Deallocates memory previously allocated for the iterator */
void zigzagIteratorFree(struct ZigzagIterator *iter) {
    free(iter);
}

/**
 * Your ZigzagIterator will be called like this:
 * struct ZigzagIterator *i = zigzagIteratorCreate(v1, v1Size, v2, v2Size);
 * while (zigzagIteratorHasNext(i)) printf("%d\n", zigzagIteratorNext(i));
 * zigzagIteratorFree(i);
 */
```