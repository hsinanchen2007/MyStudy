### 解题思路
此处撰写解题思路
如果数字i缺失的话，那么第i个数字就应该是i+1 ！= i，所以遍历数组当i !=nums[i]时表明i就是缺失的数字。但是注意还有一种情况那就是n-1缺失，这种情况的话遍历是不会发现的，所以res不会被赋值，那么我们只需要将res初始化为n-1即可。
### 代码

```c
int missingNumber(int* nums, int numsSize){
    int i,res = numsSize;
    for(i = 0;i < numsSize;i++){
        if(i != nums[i]){
            res = i;
            break;
        }
            
    }
    return res;
}
```