### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int left = 0, right = numsSize - 1 ,mid = 0;
    *returnSize = 2;
    int *a = (int*)malloc(sizeof(int) * 2);
    a[0] = -1, a[1] = -1;
        if(numsSize == 0)
        return a;
    while(left <= right)             //先找到了target
    {
           mid = (left + right)/2;
           if(nums[mid] > target)
           {
               right = mid - 1;
           }
           else if(nums[mid] < target)
               left = mid + 1;
           else 
               break;                      
    }
    printf("%d %d %d\n",mid,left,right);
    if(nums[mid] != target)       //判断是否有mid
        return a;
    else
        a[1] = mid;
    int left1 = 0,right1 = mid - 1,left2 = mid + 1, right2 = numsSize - 1;
    printf("%d %d %d\n",mid,left1,right1);
    if(right1 == left1 || right1 < 0)        //左边只剩下最后一个数
    {
        if(target == nums[left1])
        {
            a[0] = left1;
        }
    }
    while(left1 <= right1)         //找左
    {
           mid = (left1 + right1)/2;
           if(nums[mid] > target)
           {
               right1 = mid - 1;
           }
           else if(nums[mid] < target)
               left1 = mid + 1;
           else 
           {
               a[0] = mid;
               right1 = mid-1;
           }                        
    }
     printf("%d %d %d %d\n",mid,left1,right1,a[0]);
    printf("%d %d %d %d\n",mid,left2,right2,a[1]);
       if(a[0] == -1)                //左边没找到
         a[0] = a[1];                //原来的a[1] 就变成左边
    if(left2 == right2 || left2 > right2)    //右边只剩下最后一个数
    {
        if(nums[right2] == target)
        {
           a[1] = right2;
        }

    }
    while(left2 <= right2)         //找右
    {
           mid = (left2 + right2)/2;
           if(nums[mid] > target)
           {
               right2 = mid - 1;
           }
           else if(nums[mid] < target)
               left2 = mid + 1;
           else 
           {
               a[1] = mid;
               left2= mid+1;
           }                        
    }
    return a;
}
```