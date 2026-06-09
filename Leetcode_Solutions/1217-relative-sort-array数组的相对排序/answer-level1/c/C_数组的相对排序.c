### 解题思路
题目给出所有的元素都大于等于0小于等于1000，可以建立哈希表。
先把arr1转换成哈希表，在根据arr2的顺心，先写回arr1一部分数字，剩下的数字按序写回arr1即可

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    //建立hash表，初值都是0
    int* hash=(int*)malloc(sizeof(int)*1001);
    for(int i=0;i<=1000;++i)hash[i]=0;
    //哈希表中记录着arr1中每个元素出现的次数
    for(int i=0;i<arr1Size;++i)
        hash[arr1[i]]+=1;
    //i表示arr1的写入位置，先从hash表中按照arr2的次序写回数字
    int i=0;
    for(int j=0;j<arr2Size;++j)
        while(hash[arr2[j]]-->0)
            arr1[i++]=arr2[j];
    //从hash表中写回剩余的数字
    for(int j=0;j<=1000;++j)
        while(hash[j]-->0)
            arr1[i++]=j;
    //返回
    free(hash);
    *returnSize=arr1Size;
    return arr1;
}
```