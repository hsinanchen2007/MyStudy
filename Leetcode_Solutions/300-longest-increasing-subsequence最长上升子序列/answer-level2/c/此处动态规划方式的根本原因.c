int lengthOfLIS(int* nums, int numsSize)
{
    if (numsSize <= 1) 
        return numsSize;

    int lis[numsSize];
    int length = 1, index = 0;
    lis[index] = nums[0];

    for (int i = 1; i < numsSize; i++)    //遍历nums；
    {
        if (nums[i] > lis[index])
        {
            lis[++index] = nums[i];    //单独使用index；
            length++;                //加尾部才会增加长度；
        }
        else if (nums[i] < lis[index])    //小于子串尾部则往前合适位置插入替换；
        {
            if (index == 0)
                lis[index] = nums[i];    //插替换到头；
            else
            {
                for (int j = index; j >= 0; j--)    //寻找合适位置j，j-1小于当前数处；
                {
                    if (j == 0 || lis[j - 1] < nums[i])
                    {
                        lis[j] = nums[i];    //替换，但不增加长度结果值；
                        break;
                    }
                }
            }
        }
    }
    return length;
}
*总结：
	* 原数组中靠后的，小于当前第i位的数，之所以可以插入到子串中，是因为后续比较中大于第i位的数也必将大于该“前插数”！
	* 其根本原因是，往前插入替换时，要直到替换到子串尾部才会接着对“最大子串长”影响，否则并不改变length，而只是规划入子串中进行替换；

