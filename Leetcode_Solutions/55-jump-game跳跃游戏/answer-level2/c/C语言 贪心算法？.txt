### 解题思路

代码比较简单，两个for循环嵌套，加上几个if判断搞定。复杂度O(0)*O(N)大致思路是：
1.以数组的第一个元素为基础，外循环的次数取决于nums[0]。
2.内循环：从i开始往后遍历，如果nums[j]>=numsSize-j-1，则返回true，表示可以直接从当前位置到达终点(nums[numssize-1]).
2.如果遇到nums[j]==0，就从当前位置向前遍历，如果发现前面的元素都不满足nums[k]>j-k的条件，则返回 false(这句话的意思是无法从这个0前面的任何一个位置跳到0的后面，这时后面的一切遍历都没有意义了，所以直接返回 false。)

### 代码

```c
bool canJump(int* nums, int numsSize){
   int i,j,k;
   if(nums==NULL||numsSize==0)
        return NULL;
    if(numsSize==1)//出发位置即终点，直接返回 true
        return true;
    for(i=0;i<nums[0];i++)
    {
       for(j=i;j<numsSize;j++)
       {
            if(nums[j]>=numsSize-j-1)
                return true;
            if(nums[j]==0)
            {
                k=j;
                while(nums[k]<=j-k)
                {
                    k--;
                    if(k<0)
                        return false;
                }
            }
        }
    }
   return false;
}
```