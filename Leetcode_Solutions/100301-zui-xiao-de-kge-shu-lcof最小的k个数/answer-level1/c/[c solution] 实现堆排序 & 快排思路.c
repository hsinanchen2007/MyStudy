### 解题思路

1. 快排思路
2. 最大堆思路


#### 快排思路

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int* a ,int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int* arr , int start , int end ){
    int privot = arr[start];
    while(start < end){
        while(start < end && arr[end] >= privot){
            end--;
        }
        if(start < end){
            arr[start++] = arr[end];
        }
        while(start < end && arr[start] <= privot){
            start++;
        }
        if(start < end){
            arr[end--] =  arr[start];
        }
    }
    arr[start] = privot;
    return start;
}


int* quickSort(int* arr , int start , int end , int k){
    if(start < end){
        int mid = partition(arr, start , end);
        if(mid == k ){
            return arr;
        }
        if(mid > k ){
            return quickSort(arr, start , mid , k);
        }
        if(mid < k ){
            return quickSort(arr, mid + 1 , end, k);
        }
    }
    return arr;
}


int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    if(arr == NULL || arrSize < 0){
        *returnSize = 0;
        return NULL;
    }
    if(arrSize == 0 || k == 0 || arrSize < k){
        *returnSize = 0;
        return arr;
    }
    *returnSize = k;
    return quickSort(arr, 0 , arrSize -1 , k );
}


```


#### 堆排序


```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int* a , int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapSort(int* arr , int i , int len){
    int temp , ch ;
    for( temp = arr[i] ; ( i*2+1 ) < len ; i = ch){
        ch = i*2 + 1;
        if((ch + 1) < len && arr[ch + 1] > arr[ch]){
            ch++;
        }
        if(temp < arr[ch]){
            arr[i] = arr[ch];
        }else{
            break;
        }
    }
    arr[i] = temp;
}


int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int* res = (int*)malloc(sizeof(int)*k);
    *returnSize  = k;

    // 初始化最大堆
    for(int i = arrSize / 2 -1 ; i >= 0  ; i--){
        heapSort(arr , i , arrSize);
    }

    for(int i = arrSize -1 ; i > 0 ; i--){
        swap(&arr[0] , &arr[i]);
        heapSort(arr , 0 , i);
    }
    for(int i = 0 ; i < k ; i++){
        res[i] = arr[i];
    }
    return arr;
}
```