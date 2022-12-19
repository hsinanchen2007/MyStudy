方法1：双指针

```
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int low = 0, high = numbersSize - 1;
    
    while (low < high){
        int cmp = numbers[low] + numbers[high];
        if (cmp > target)
            high -= 1;
        else if (cmp < target)
            low += 1;
        else{
            break;
        }
    }
    *returnSize = 2;
    int *res = (int*)malloc(sizeof(int) * 2);
    res[0] = low + 1;
    res[1] = high + 1;
    return res;
}

```

方法2：二分法

```
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int i, l, r, m, flg = 0;
   
    for (i = 0; i < numbersSize - 1; i++){ 
        l = i + 1, r = numbersSize - 1;
        while (l <= r){
            m = (l + r) / 2;
            if (numbers[m] > target - numbers[i])
                r = m - 1;
            else if (numbers[m] < target - numbers[i])
                l = m + 1;
            else{
                flg = 1;
                break;
            }
        }
        if (flg)
            break;
    }
    *returnSize = 2;
    int *res = (int*)malloc(sizeof(int) * 2);
    res[0] = i + 1;
    res[1] = m + 1;
    return res;
}

```
方法3：暴力法

```
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int i, j, flg = 0;

    for (i = 0; i < numbersSize - 1; i++){
        for (j = i + 1; j < numbersSize; j++){
            if (numbers[i] + numbers[j] == target){
                flg = 1;
                break;
            }
        }
        if (flg || numbers[i] > target)
            break;
    }
    *returnSize = 2;
    int *res = (int*)malloc(sizeof(int) * 2);
    res[0] = i + 1;
    res[1] = j + 1;
    return res;
}
```

