![image.png](https://pic.leetcode-cn.com/0d10870498d1cbcdd641ffef3eb995a1ed592dcd42b14d59d89f7d78294faa1c-image.png)

```
 typedef struct
 {
     int value;
     int index;
 }item_s;

 int compare(void *a, void *b)
 {
    item_s *ptr1,*ptr2;

    ptr1 = (item_s*)a;
    ptr2 = (item_s*)b;

    if(ptr1->index != -1 && ptr2->index != -1)
    {
        return ptr1->index - ptr2->index;
    }
    if(ptr1->index != -1 && ptr2->index == -1)
    {
        return -1;
    }
    if(ptr1->index == -1 && ptr2->index != -1)
    {
        return 1;
    }
    if(ptr1->index == -1 && ptr2->index == -1)
    {
         return ptr1->value - ptr2->value;
    }

    return 0;
 }
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){

    int *res = NULL;
    item_s *ptr = NULL;
    int table[1001] = {-1};
    for(int i = 0; i < 1001;i++)
    {
        table[i] = -1;
    }

    for(int i = 0; i < arr2Size; i++)
    {
        table[arr2[i]] = i;
    }
    res = malloc(sizeof(int)*arr1Size);
    ptr = malloc(sizeof(item_s)*arr1Size);
    for(int i = 0; i < arr1Size; i++)
    {
        ptr[i].value = arr1[i];
        ptr[i].index = table[arr1[i]];
    }
    qsort(ptr,arr1Size,sizeof(item_s),compare);

    for(int i = 0; i < arr1Size; i++)
    {
        res[i] = ptr[i].value;
    }

    *returnSize = arr1Size;
    return res;
}
```
