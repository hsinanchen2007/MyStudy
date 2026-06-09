**思路就是设置一个标记数 比如说 1 1 1 2 2 3 起初把标记数设为1 然后新数组的
下标设为index=0(这个新数组不是说重新又建了一个数组而是说把符合条件的数再重
新存入这个数组) 然后从0位置遍历数组如果这个数为1 (即为当前的标记数)并且num
(num是标记数出现的次数)<2 (即这个数还未出现两次的话)，就把它存入“新数组”  
否则跳过这个数  如果当前位置的数和标记数不一样的话就重新修改标记数**

```
int removeDuplicates(int* nums, int numsSize){
     if(numsSize==0)
        return 0;
    int now=nums[0];//设置标记数为第一个数
    int num=0;//设置标记数出现的次数
    int index=0;//下标
    int i=0;//用于遍历
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]==now)//如果这个数等于标记数
        {
            if(num<2)//这个数还未出现两次了
            {
                nums[index]=nums[i];//把这个数重新存入数组
                index+=1;
                num+=1;
            }
        }
        else
        {
            now=nums[i];//修改标记数
            nums[index]=nums[i];//把这个数重新存入数组
            index+=1;
            num=1;
        }
    }
    return index;
}
```
