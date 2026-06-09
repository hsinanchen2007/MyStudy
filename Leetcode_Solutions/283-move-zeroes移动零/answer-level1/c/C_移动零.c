### 解题思路
两个指针，一个修改，一个探测。
修改位从第一个值为零的位置开始，每次修改向后移动到下一个为零的位置。
探测位置从修改位置的下一个位置开始向后探测非零值，如果有，把第一个探测到的非零值写入修改位，探测位非零值置零。
循环这个过程直到探测位没有探测到非零值。

### 代码

```c
void moveZeroes(int* nums, int numsSize){
    int i=0;//修改位    
    while(1)
    {
        while(i<numsSize&&nums[i]!=0)++i;
        int j=i+1;
        while(j<numsSize&&nums[j]==0)++j;
        if(j>=numsSize)break;
        nums[i]=nums[j];
        nums[j]=0;   
    }
}
```