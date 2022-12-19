### 解题思路
这题使用暴力求解的思路不难，但前几次一提交就报出栈溢出的错误，后来发现是自己理解错了函数中returnSize参数的含义，以为是要输出数组的首地址，经过浏览其他同学的答案才搞明白参数的含义。看来自己对于力扣解题的模式以及C语言的基础还是不够熟悉，要多多练习了，另外还有其他解题思路还没有使用过。

### 代码

```c
/**暴力法求解
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target,int *returnSize){
        int i,j;
        int *p=(int *)malloc(sizeof(int)*2);//需要动态分配内存
		  for(i=0;i<numsSize-1;i++)
		  {
		  	int temp=target-nums[i];
		  	for(j=i+1;j<numsSize;j++)
		  	{
		  		if(temp==nums[j])
		  		{
		  		  p[0]=i;
		  		  p[1]=j;
                  *returnSize=2;//返回数组大小
		  		  return p;
		  		}
		  	}
		  	
		  }      
        *returnSize=0;
		return p;  
              
}
```