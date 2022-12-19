题目要求：arr2中元素必定出现在arr1中，并且要按照arr2中元素顺序输出arr1的元素。
投机取巧思路：
1.升序排序arr1，为了确保arr2没有的元素是升序
2.建立hash_exit[1001]数组，把数组中以arr2元素对应的下标的值置为1
3.建立hash_times[1001]数组，记录arr1中元素出现的次数
4.建立一个临时数组temp，遍历arr2，因为arr2中元素必定存在于arr1中，就不需要去查hash_exit看元素是否存在，只用按照元素在arr1中出现的次数，依次放在temp数组中，直到次数为0.
5.遍历arr1，顺序查hash_exit找不存在的，并放入temp中，由于之前已经排好顺序，所以不存在的元素一定是升序放在temp中的
**缺点：没有达到双百**
执行用时 :
4 ms
, 在所有 C 提交中击败了
90.47%
的用户
内存消耗 :
5.7 MB
, 在所有 C 提交中击败了
100.00%
的用户
```
void sort_arr1(int *arr,int n){
    for(int i=1;i<n;i++){
        int temp = arr[i];
        int j;
        for(j=i;j>0 && temp < arr[j-1];j--)
            arr[j] = arr[j-1];
        arr[j] = temp;
    }
}
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    //排序arr1
    sort_arr1(arr1,arr1Size);
    //hash_exit记录arr1中与arr1中相同元素
    //hash_times记录1中元素存在的次数
    int hash_exit[1001] = {};
    int hash_times[1001] = {};
    for(int i=0;i<arr1Size;i++){
        hash_times[arr1[i]]++;
    }
    for(int i=0;i<arr2Size;i++){
        hash_exit[arr2[i]] = 1;
    }
    //临时数组，存放排好序的元素
    int *res = (int *)malloc(arr1Size*sizeof(int));
    int index = 0;
    //遍历arr2[]
    for(int k=0;k<arr2Size;k++){
        while(hash_times[arr2[k]]--)
            res[index++] = arr2[k];
    }
    for(int i =0;i<arr1Size;i++){
        if(hash_exit[arr1[i]] == 0)
            res[index++] = arr1[i];
    }
    *returnSize = arr1Size;
    return res;
}
```
