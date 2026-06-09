1.排序
2.筛选
```

bool containsNearbyDuplicate(int* nums, int numsSize, int k){

    if (nums == NULL) {
        return false;
    }
    
    if (numsSize <= 1) {
        return false;
    }

    NumNode *data = (NumNode*)malloc(sizeof(NumNode) * numsSize);
    if (data == NULL) {
        return false;
    }
    memset(data, 0, sizeof(NumNode) * numsSize);
    
    for(int i = 0; i < numsSize; ++i) {
        data[i].data = nums[i];
        data[i].index = i;
        //printf("%d,%d\n", data[i].index, data[i].data);
    }
    
    qsort(data,numsSize,sizeof(NumNode),numNodeCompareFunc);
    
    int compareIndex = 0;
    NumNode compareNode = data[compareIndex];
    for(int compareIndex = 1; compareIndex < numsSize; ++compareIndex) {
        if (compareNode.data == data[compareIndex].data) {
            int diff = compareNode.index - data[compareIndex].index;
            //printf("%d,%d\n", compareNode.index, compareNode.data);
            //printf("%d,%d,diff %d\n", data[compareIndex].index, data[compareIndex].data, diff);
            if (abs(diff) <= k) {
                return true;
            }
            compareNode = data[compareIndex];
        } else {
            compareNode = data[compareIndex];
        }
    }
    
    
    return false;
}


```
