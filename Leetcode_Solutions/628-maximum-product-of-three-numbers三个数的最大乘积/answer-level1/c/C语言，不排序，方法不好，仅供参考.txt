首先，三个数的最大乘积就是三个最大数的乘积或者是两个最小数和一个最大数乘积，因此我将两者找出，做一个对比。
最开始，我选择了冒泡排序来寻找最大和最小，但是超出了时间限制，因此我决定直接寻找。
代码如下：

int maximumProduct(int* nums, int numsSize)
{
    int a;
    int max1 = 0, max2 = 0, max3 = 0, min1 = 0, min2 = 0;//都是下标，max1就是最大的数的下标，max2就是第二大数的下标，以此类推
    for(a = 0; a < numsSize; a++)
    {
        if(nums[a] > nums[max1])//遍历，如果有比max1大的数，则把大数角标赋给max1
            max1 = a;
        if(nums[a] < nums[min1])//小数同理
            min1 = a;
    }
    
    for(a = 0; a < numsSize ; a++)
    {
        if(a == 0)//第一个数如果就是最大，那么其他的数无法大过我所预设的max2，就会出现无法赋值的情况，因此单独讨论
        {
        if(max1 == 0)
        max2 = 1;
        }
        if(a == max1)//跳过最大的数，再用相同的算法找第二大的数
        continue;
        if(nums[a] > nums[max2])
            max2 = a;
    }
    
    for(a = 0; a < numsSize; a++)//同理
    {
        if(a == 0)
        {
        if (min1 == 0)
        min2 = 1;
        }
        if(a == min1)
        continue;
        if(nums[a] < nums[min2])
            min2 = a;
    }
    
    for(a = 0; a < numsSize; a++)//同理
    {
        if(a == 0)
        {
        if(max1 == 0 || max2 == 0)
        {
            if(max1 == 1 || max2 == 1)
            max3 = 2;
            else max3 = 1;
        }
        }
    
        if(a == max1 || a == max2)
        continue;
        if(nums[a] > nums[max3])
            max3 = a;
    }

    
    int zheng, fu; 
    zheng = nums[max1] * nums[max2] * nums[max3];//三个最大值的乘积
    fu = nums[max1] * nums[min1] * nums[min2];//两个最小值和一个最大值的乘积
    
    if(numsSize == 3)//比大小
        return nums[0] * nums[1] * nums[2];
    else if(numsSize != 3 && (zheng > fu))
        return zheng;
    else return fu;
    
}

