解法思路依据每个位如果是3的倍数就认为是没多出的，不是3的倍数的位说明是数量为1的那个数的位。
```
int singleNumber(int* nums, int numsSize){
    unsigned int ans = 0;//定义为无符号来避免left shift of 1 by 31 places cannot be represented in type 'int'
    for(int i = 0,j = 0,count = 0; i<32; i++)
    {
        for(j = 0,count = 0; j<numsSize; j++)
        {
            if((nums[j]>>i)&1)count++;
        }
        if(count%3 != 0 )
        {
            ans = ans | 1u<<i;//1u避免left shift of 1 by 31 places cannot be represented in type 'int'
            if(i == 31)return (int)-(~(ans-1));//这里的第31位（从第0位开始算）如果为1就说明是负数，将其按反码+1=补码反推得到负数绝对值的原码
                                                //然后价格符号转成有符号就行     
        }

    }  
    
    return ans ;
}
时间打败94%
```
