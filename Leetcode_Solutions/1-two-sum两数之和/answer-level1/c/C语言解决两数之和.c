### 解题思路
用C语言暴力解法。两个嵌套的for循环进行查找。根据题目要求自行创建新数组。创建时，假如出现
>>load of null pointer of type 'const int'


说明函数返回的指针指向函数内变量，当函数退出后，变量存储空间被销毁。所以可以用static去修饰变量，也可以malloc函数分配内存空间，也可以使用全局变量。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target,int *returnSize){
    static int ans[2]={0};
    for(int i=0;i<numsSize-1;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                *returnSize=2;
                ans[0]=i;
                ans[1]=j;
                return ans;
            }
        }
    }
    *returnSize=0;
    return ans;
}
```