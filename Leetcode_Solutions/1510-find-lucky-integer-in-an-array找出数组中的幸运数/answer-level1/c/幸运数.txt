### 解题思路
建立哈希表
需要返回最大的幸运数，逆序遍历即可

### 代码

```c
int findLucky(int* arr, int arrSize){
    int *res=(int*)malloc(sizeof(int)*501);
    memset(res,0,sizeof(int)*501);
    int i;
    for(i=0;i<arrSize;i++){
        res[arr[i]]++;
    }
    for(i=500;i>=1;i--){
        if(res[i]==i)
            return i;
    }
    return -1;
}
```