### 解题思路
用异或运算
a^0=a
a^a=0
将数组中的数与0,1,2,3......numsSize全部异或，得到的数就是结果
例如：数组：3.0.1
3^0^1^0^1^2^3=2
因为出现在数组中的数肯定都会与自身异或成0，最终只剩下0^未在数组中出现的数=未在数组中出现的数

### 代码

```c
int missingNumber(int* nums, int numsSize){
int i,temp=0,temp1=0;
for(i=0;i<numsSize;i++)
{
    temp=temp^nums[i];
 
}
for(i=0;i<=numsSize;i++)
{
   temp=temp^i;
}
return temp ;
}
```