### 解题思路
暴力破解

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *re=calloc(2,sizeof(int));
    re[0]=-1;re[1]=-1;
    *returnSize=2;
    int flag=0;
    for(int i=0;i<numsSize;i++){
        if(flag==0&&nums[i]==target){
            re[0]=i;
            re[1]=i;//为了对付只有一个target元素的情况
            flag=1;
        }
        //flag==1，则表示该元素不是第一个值为target的元素
        else if(flag==1&&(i==numsSize-1)&&nums[i]==target)//最后一个target元素，是在最后一个位置的情况
            re[1]=i;
        else if(flag==1&&nums[i]!=target){//下面一个不是target的元素，re[1]=i-1，并且跳出循环
            re[1]=i-1;break;
        }
            
    }
    return re;
}
```