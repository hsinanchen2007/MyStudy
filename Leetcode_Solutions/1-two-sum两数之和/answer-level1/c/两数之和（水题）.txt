### 解题思路
强调leecode中的一个“奇葩”Note：
![1.png](https://pic.leetcode-cn.com/196b14bc1d692b1594b9bef7581fdc77bb3808f7cbef6ae3494d27667cfaa0bb-1.png)
大致意思是：返回值数组必须被分配内存，假定调用该方法的调用这调用free()方法。
可以参考[解决方法](https://blog.csdn.net/qq_34824576/article/details/86496130)

此外我实在不知道参数 int* returnSize到底有什么必要？？？，其实换位思考只是对我编程的时候没有必要吧，但是对调用者有必要。

建议参考：[分糖果II、指针作为返回值注意点、memset()注意点、malloc()什么时候使用](https://leetcode-cn.com/problems/distribute-candies-to-people/solution/fen-tang-guo-ii-zhi-zhen-zuo-wei-fan-hui-zhi-zhu-y/)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j;
    int *result=(int*)malloc(sizeof(int)*2);
    memset(result,0,sizeof(int)*2);

    *returnSize=2;
    for(i=0;i<numsSize;i++){
        result[0]=i;
        int temp=target-nums[i];
        for(j=i+1;j<numsSize;j++){
            if(nums[j]==temp){
                result[1]=j;
                return result;
            }
        }
    }
    return result;
}
```