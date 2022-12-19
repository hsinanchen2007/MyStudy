### 解题思路

本解题执行0ms,内存5.9M在所有c提交中均为打败100%,以下代码仅供参考
### 代码
**解题思路:将相等val的数放在数组最后一位，相等val后面的数整体前移**

count来判断等于val的个数，每当相等的时候后面的所有元素均往前移一个单位，一定要自己想特殊的例子进行测试，前提是要满足所给的参考案例，比如[0,1,2,2,3,0,4,2,2],val=2,这里有四个2，但是当前面两个2移到后面去后会形成四个2，前面已经判断了两次，这个时候需要判断程序，不然到最后第一个for在最后四个2处会进入无限循环！

```c
int removeElement(int* nums, int numsSize, int val){
    int i,j;
    int count=0;
    int temp;
    for(i=0;i<numsSize;i++)
        if(nums[i]==val)
            count++;
    int n=0;
    for(i=0;i<numsSize;i++)
    {
      
        if(nums[i]==val)
        {
            n++;
            if(n>count)
                break;//重点
            temp=nums[i];
            for(j=i;j<numsSize-1;j++)
            {
                nums[j]=nums[j+1];
            }
            nums[j]=temp;
            i--;//这里要减一个1，因为后一个数会到此处，我要在下一次继续判断
        }
    }
    return numsSize-count;//看说明
}
```