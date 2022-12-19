### 解题思路
其实这种方法也有点动态规划的感觉：（不知我是不是对动规划有误解）
记录上一个窗口的最大值的下标maxIndex，然后与本次的窗口的末端(nums[end])相比较。若
`nums[maxIndex]<=nums[end]`，则更新maxIndex，否则就只能遍历整个窗口的所有值来得到最大值。(具体见代码)
这种方式的原理是相邻两个窗口之间有k-1个相同的值，因此若maxIndex存在于当前的窗口中，就不必一个给比较窗口中除了nums[end]之外的值。
这种方式的时间复杂度考虑最坏情况为O(Nk)，N为数组nums中元素个数；空间复杂度为O(N-k+1),用于输出数组


参考：[不使用数据结构，双100%](https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/solution/bu-shi-yong-shu-ju-jie-gou-shuang-100-by-sun-239/)、[滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/solution/hua-dong-chuang-kou-zui-da-zhi-by-leetcode-3/)
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    if(nums==NULL||numsSize==0||k<=0||numsSize<k){
        *returnSize=0;
        return NULL;
    }
    *returnSize=numsSize-k+1; 
    int start=0,end;
    int *ans=(int*)malloc(sizeof(int)*(numsSize-k+1));
    int j=0,i=0;
    //limits.h头文件中的INT_MIN
    int max;
    int maxIndex=-1;
    for(start=0,end=k-1;end<numsSize;end++,start++){
        printf("start=%d,end=%d\t",start,end);
        //判断maxIndex是否在滑动窗口内
        if(maxIndex>=start&&maxIndex<=end){
            //如果在滑动窗口内则只需判断nums[end]是否大于nums[maxIndex]
            if(nums[end]>=nums[maxIndex]){
                maxIndex=end;
            }
        }else{
            maxIndex=start;
            //否则就原始地遍历这个窗口找到最大值
            for(i=start+1;i<=end;i++){
                if(nums[i]>=nums[maxIndex]){
                    maxIndex=i;
                } 
            }
        }
        ans[j]=nums[maxIndex];
        j++;
    }

    return ans;
}
```