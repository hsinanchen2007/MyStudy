### 解题思路
前k个最小数字，当k≥5时，堆比冒泡和简单选择排序好,初次建立堆的比较次数不超过4n。

### 代码

```c
void BuildMinHeap(int* arr,int arrSize){
    for(int i=arrSize/2-1;i>=0;i--){
        AdjustDown(arr,arrSize,i);
    }
}

void AdjustDown(int* arr,int arrSize,int i){
    int temp = arr[i];
    for(int j=i*2+1;j<arrSize;j=j*2+1){
        if(j+1<arrSize && arr[j+1]<arr[j]){
            j++;
        }
        if(temp <= arr[j]){
            break;
        }
        arr[i] = arr[j];
        i = j;
    }
    arr[i] = temp;
} 

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    BuildMinHeap(arr,arrSize);
    *returnSize = k;
    int* result = (int*)malloc(sizeof(int)*k);
    for(int i=0;i<k;i++){
        result[i] = arr[0];
        int temp = arr[0];
        arr[0] = arr[arrSize-1-i];
        arr[arrSize-1-i] = temp;
        AdjustDown(arr,arrSize-i-1,0);
    }
    return result;
}
```