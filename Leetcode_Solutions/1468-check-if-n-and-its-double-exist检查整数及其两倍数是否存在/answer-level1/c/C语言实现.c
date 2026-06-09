### 解题思路
1 临时数组存储原数组扩大2倍后的数值
2 比较临时数据和原数组
### 代码

```c
bool checkIfExist(int* arr, int arrSize){
    //入参检查
    if(arr == NULL)
    {
        return false;
    }

    //将整个数组扩大二倍
    int tmp[arrSize];
    int i =0;
    for(i=0; i<arrSize;i++)
    {
        tmp[i] = arr[i]*2;
    }

    //找原数组中是否存在相同的数,二分查找
    //bool rel = false;
    for(i=0; i<arrSize;i++)
    {
        for(int j =0; j<arrSize;j++)
        {
            if((tmp[i] == arr[j]) && (i != j))
            {
                return true;
            }
        }
    }
    return false;
}
```