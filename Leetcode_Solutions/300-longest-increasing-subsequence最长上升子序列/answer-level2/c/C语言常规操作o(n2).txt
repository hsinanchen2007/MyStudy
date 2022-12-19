### 解题思路
动态规划是这道题的常规打法。
整体打法是，建立一个数组len1[],每一个元素记录[0..i-1]和i组成的最长升序子串长度。最后一波检索最大len[]元素。注意，不能把"[0..i-1]和i"理解成[0..i]，一字之差就偏离本意了。
难点还是在求“[0..i-1]和i组成的最长升序子串的长度"
利用双循环，外层用来遍历题目中的序列，内层用来更新len[]。
在遍历过程中，可能i与[0..i-1]的元素能组成多种升序序列，长度不同，所以在内循环中一边遍历，一边比较出最长的序列大小，不断更新元素len[i]。
特殊情况：如果循环过后，i比[0..i-1]元素都小，意味着i只能和它自己组成升序序列，长度1。
### 代码

```c
int lengthOfLIS(int* nums, int numsSize){
    if(numsSize==0){
        return 0;
    }
    int *len=(int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++){
        len[i]=1;
    }
    len[0]=1;int ml=0;
    for(int i=1;i<numsSize;i++){//代码关键部分，前面已经详解了
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]&&len[i]<len[j]+1){
                len[i]=len[j]+1;
            }
        }
    }
    int output=0;//输出len最大元素
    for(int i=0;i<numsSize;i++){
        if(len[i]>output){
            output=len[i];
        }
    }
    return output;
}
```