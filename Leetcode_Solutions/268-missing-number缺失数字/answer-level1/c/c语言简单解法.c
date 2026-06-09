### 解题思路
此处撰写解题思路

### 代码

```c
int missingNumber(int* nums, int numsSize){
    int i,j;
    for(i=0;i<=numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(i==nums[j])
                break;
            else if(i!=nums[j]&&j==numsSize-1)
                return i;
            else
                continue;
        }
    }
    return i;
}
```基本条件判断，0到numsSize中必会有那个缺失的数字，从0到numsSize进行遍历，和nums依次比对，找不到就返回。