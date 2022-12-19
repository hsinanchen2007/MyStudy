话说。很简单的题目呀，怎么被大佬们一分析，我就看不懂了呢。。。。。

第一反应hash数组，然而题目说要使用额外常数空间
注意到仅仅缺失了一个数字，所以可以遍历数组，将所有的数相加sum，同时记录下最大的值max，然后用1-max的和减去sum的值，差就是缺少的那个数
纠错，发现此方法的一个问题，如果最大值是缺少的那个呢？于是又发现，最大值是numsSize。。。


        int missingNumber(int* nums, int numsSize){
            int sum = 0;
            
            for(int i = 0; i < numsSize; i++)
                sum+=nums[i];

            return (1+numsSize)*numsSize/2-sum;
        }