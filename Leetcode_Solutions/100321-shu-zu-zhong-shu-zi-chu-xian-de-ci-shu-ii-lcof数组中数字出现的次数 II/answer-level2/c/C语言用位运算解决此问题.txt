### 解题思路
理论基础：某一数字出现3次，则他们每一位的和分别可以被3整除
         如数字7：0111，第0位为1，3个1加起来为11，可以被三整除。第二第三位同理。
解题思路：
        1. 分别给数组中所有数字不同位分别求和，结果记录为temp，int型要分别求32次。
        2. 若第i位的求和结果temp能被3整除，说明只出现了1次的那个数字该位为0，否则为1.
        3. 根据第二部结果，给result的第i位置1或0。（置0可以不做处理）。


### 代码

```c
int singleNumber(int* nums, int numsSize){
    int result = 0;
    for(int i = 0; i < 32; i++){//遍历32位
        int temp = 0;//记录所有数字第i位的和
        for(int j = 0; j < numsSize; j++){
            temp += (nums[j] >> i) & 1;//求第i位之和
        }
        if(temp % 3){
            result += 1 << i;//置1
        }
    }
    return result;
}
```