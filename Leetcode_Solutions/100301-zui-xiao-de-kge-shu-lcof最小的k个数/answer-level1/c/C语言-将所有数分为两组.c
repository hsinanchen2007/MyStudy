### 解题思路
不需要对所有数排序,只需要确保前k个数全都小于后面的数,将数组中的数分为大小两组
遍历前k个数,每个数与第k个之后的所有数比较,若当前数大则交换,一遍循环使当前数比后面所有数小
这两组数内部的顺序不需要关心,两层循环容易理解,但时间复杂度爆炸
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    for(int i=0;i<k;i++){
        for(int j=k;j<arrSize;j++){
            if(arr[i] > arr[j]){
                arr[i] = arr[i]^arr[j];//使用异或实现交换
                arr[j] = arr[i]^arr[j];
                arr[i] = arr[i]^arr[j];
            }
        }
    }
    *returnSize = k;
    return arr;
}
```