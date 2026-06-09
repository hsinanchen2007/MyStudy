
![result.png](https://pic.leetcode-cn.com/e5c845dad6d8943e8da1976465e2e15168835469347e68ee9b509bb807fabc6d-result.png)


由于输入的数组及数组中的元素，可以使用类似计数排序的思路：
```
int findLucky(int* arr, int arrSize){
    int num_count[501] = {0};
    int i = 0;

    for(i = 0; i < arrSize; i ++){
        num_count[arr[i]] ++;
    }

    for(i = arrSize; i > 0; i --){
        if(num_count[i] == i){
            return i;
        }
    }
    return -1;
}
```


