第一次用leetcode,感觉自己代码白学了。希望自己能坚持下去吧。以下是参考大佬们的解法之下，自己改的。运行时间4S.由于C语言不能直接返回数组。于是用了指针*a,来返回数值。使用指针时要用malloc生成一个内存为2的结点，不然会报错。唔，returnSize应该指的是[a,b,c,d,...n]的返回值类型。题目要求返回两个数，所以赋值为2.以上就是不懂+修改的地方，还请大家多多指教哇！
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j;
    int *a=(int *)malloc(sizeof(int)*2);
   // int *a;
    for(i=0;i<numsSize-1;i++)
     {
      for(j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                a[0]=i;
                a[1]=j;
                *returnSize=2;
                return a;
            }
        }
     }
        *returnSize=0;
        return 0;
}