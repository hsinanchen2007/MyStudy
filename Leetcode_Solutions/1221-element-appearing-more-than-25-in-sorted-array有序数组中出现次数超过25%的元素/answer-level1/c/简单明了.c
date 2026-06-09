### 解题思路
此处撰写解题思路
算法思想：
(1)	数组有序，且某元素出现次数超过25%
(2)	那么对于此元素第一次出现位置，加25%数组长度，必定仍为它自身


### 代码

```c
int findSpecialInteger(int* arr, int arrSize){
    for(int *p = arr,*q=arr+arrSize/4;;p++,q++){
        if(*p==*q) return *p;
    }
    return 0;
}
```