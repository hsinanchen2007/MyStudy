### 解题思路
用snprintf函数将整形转换为字符串后，采用strlen来判定长度是否为偶数位

### 代码

```c
int findNumbers(int* nums, int numsSize){
     int i, res = 0;
     char temp[6] = {0};
     for(i = 0; i<numsSize; i++)
     {
        memset( temp, 0, sizeof(temp) );
        snprintf( temp, sizeof(temp), "%d",  nums[i] ); 
        if( 0 == strlen(temp)%2 )
        {
            res++;
        }
     }

     return res;
}
```