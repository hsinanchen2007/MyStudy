### 解题思路
开始定义num，count表示一个数及目前存在数量，从头尾同时遍历，如果不同就抵消进行下一次循环，相同则判断count是否为0，若为0则此数是目前出现次数最多的那个数赋值给num，否则和num比较，相同则count+2，否则-2；最后如果count不为零则返回num，为零则-1。
有可能出现特殊情况，即数组中间数，此时判断count如果为零将它作为num，并验算，如果count不为零则判断它与num是否相等。

### 代码

```c
int majorityElement(int* nums, int numsSize){
    if(numsSize==1)
        return nums[0];
    int num,count=0;
    num=-1;
    int i=0,j=numsSize-1;
    while(i<=j)
    {
        if(i==j)
        {
            if(count==0)
            {
                num = nums[i];
                int x=0;
                for(int n=0;n<numsSize;n++)
                {
                    if(nums[n]==num)
                        x++;
                }
                if(x>numsSize/2)
                    return num;
                else 
                    return -1;

            }
                
            if(nums[i]==num)
            {
                count++;
            }
            else
                count--;
        }
        if(nums[i] == nums[j])
        {
            if(count == 0)
            {
                num = nums[i];
                count +=2;
            }
            else
            {
                if(num!=nums[i])
                    count -=2;
                else 
                    count +=2;
            }
        }
        i++;
        j--;
    }
    if(count)
        return num;
    return -1;
}
```