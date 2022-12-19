**思路**
用排好序的A和B数组进行比较，如果是A的值大于B的值就把A的值存入原来没排好序的B数组索引的位置，小于的话就把A的值存入B数组值的索引的位置，
如果最大的索引的位置存了值，则存倒数第二，以此类推。
**此题贪心的思想**
每次A都是以比B大一点的数来抵消B的数，从而达到最好。
```
struct side
{
    int val;
    int tige;
}; // 这个结构体的目的是用来存B数组的值和索引
int cmp(const void * a, const void * b) // 这个是结构体的比较器
{
    struct side * c, * d;
    c = (struct side *) a;
    d = (struct side *) b;
    return c -> val - d -> val;
}
int cmp1(const void * a, const void * b) // A数组的比较器
{
    return *(int *) a - *(int *) b;
}
int* advantageCount(int* A, int ASize, int* B, int BSize, int* returnSize){
    int i, l = 0, r = BSize - 1; // r作用是记录排好序B数组最大的值的位置
    struct side * head;
    int *list; // 是用来还回的数组
    // 创数组
    list = (int *)malloc(sizeof(int) * (ASize + 2));
    head = (struct side *)malloc(sizeof(struct side) *(BSize + 2));
    
    for (i = 0; i < BSize; i++) // 把B数组的值赋给结构体
    {
        head[i].val = B[i];
        head[i].tige = i;
    }
    qsort(A, ASize, sizeof(int), cmp1); // 进行排列
    qsort(head, BSize, sizeof(struct side), cmp); 
    for (i = 0; i < ASize; i++)
    {
        if(A[i] > head[l] . val) // 如果A数组的值大于B数组的值则把A[i]的值赋给list数组中的B数组的索引。
        {
            list[head[l] . tige] = A[i];
            l++;
        }
        else
        {
            list[head[r] . tige] = A[i]; // 如果是小于等于则把A[i]的值放在list数组中B数组最大的索引位置。
            r--;
        }
    }
    *returnSize = ASize;
    return list;
}

```