### 解题思路
设置三个变量i,j,k分别表示三个数组的初试位置
由于数组严格递增，所以在每次比较时，将值位最小的位加一（注意不一定是一个，有可能是两个，所以用三个if）

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* arraysIntersection(int* arr1, int arr1Size, int* arr2, int arr2Size, int* arr3, int arr3Size, int* returnSize){
    int i=0,j=0,k=0;
    *returnSize=0;
    int *res=(int*)malloc(sizeof(int)*arr1Size);
    while(i<arr1Size&&j<arr2Size&&k<arr3Size)
    {
        if(arr1[i]==arr2[j]&&arr2[j]==arr3[k])
        {
            res[(*returnSize)++]=arr1[i];
            i++;
            j++;
            k++;
        }
        else
        {
            int min=arr1[i]<arr2[j]?arr1[i]:arr2[j];
            min=min<arr3[k]?min:arr3[k];
            if(arr1[i]==min)
                i++;
            if(arr2[j]==min)
                j++;
            if(arr3[k]==min)
                k++;
        }

    }
    return res;

}
```