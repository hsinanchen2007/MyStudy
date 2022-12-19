### 解题思路
1、单纯摩尔投票法在本题中没有办法确定留下来的数是否是多于一半的数字，比如（[1,2,1,2,3]）,不知道是不是我对摩尔投票法理解不对，欢迎大家指出；
2、针对上面例子，所以最后剩下的数字必须要做一次遍历确认。

### 代码

```c
int majorityElement(int* nums, int numsSize){
    int major_num =nums[0];
    int count = 1;
    for(int i = 1; i < numsSize; i++ )
    {
        if(major_num == nums[i])
        {
            count++;
        }
        else
        {
            count--;
            if(count == 0)
            {
                count = 1;
                if(i < numsSize - 1)
                {
                    major_num = nums[++i];
                   
                }
                else
                {
                    return -1;
                }
                
            }
        }
    }
    if(count > 1)
    {
        return major_num;
    }
    int sum = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == major_num)
        {
            sum++;
        }
    }
    
    return sum > (numsSize >> 1) ? major_num : -1;

}
```