### 解题思路
异或法的理论基础是 
1、任何数和自己异或结果为0；
2、任何数和0异或结果为自身；
迎刃而解
### 代码

```c
int singleNumber(int* nums, int numsSize){
    int output=nums[0];
    for(int i=1;i<numsSize;i++){
        output=output^nums[i];
    }
    return output;
}
```