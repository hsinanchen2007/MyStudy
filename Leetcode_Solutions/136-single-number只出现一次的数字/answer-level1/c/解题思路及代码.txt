### 解题思路
1、利用异或思想：2个相同的数异或的结果是0；0异或任何数都等于原数本身

### 代码

```c
int singleNumber(int* nums, int numsSize){
    int i;
    int ret = 0;

    for(i=0;i<numsSize;i++){
        ret = ret ^ nums[i];
    }

    return ret;
}
```