![1.PNG](https://pic.leetcode-cn.com/cb3ca9d55a9a9cca9de2dd4a1d5c73bd13512df172144cd9f55e3c2c20b26cf2-1.PNG)

1. 首先，粗筛选，将无法整除，数组中最大值超出平均值的情况过滤掉；
2. 然后，计算得到一共需要几个子集，也就是如下代码中的needfind
3. 遍历数组，累加等于平均值的，直接返回，继续往后遍历，needfind == 0 的时候，就是成功分组的时候
4. 遍历中如果小于平均值，就继续累加
5. 对于已经访问过的打上标记，这些标记的也就是已经归于一个子集的元素；
6. 重点： 理解嵌套的这个逻辑，
7.       假设一共是5个数：A,B,C,D,E，A+B+C都小于平均值，A+B+C+D又大于平均值时，接下来会执行A+B+C+E，
          依次类推，A+B+C+E也大于平均值，就执行：A+B+D，
        累加不成功的情况，元素的used标记会清空为未使用状态

#define MAX_ARRY_NUM (16)


bool dfs(int* nums, int numsSize, int target, int needfind, int start, int cursum, int* used)
{
	int i = 0;
	bool ret = false;

	//printf("needfind:%d, start:%d, cursum:%d\n", needfind,start, cursum);

	if (0 == needfind)
	{
		return true;
	}
	if (start >= numsSize)
	{
		return false;
	}
	for (i = start; i < numsSize; i++)
	{
		if (0 < used[i])
		{
			continue;
		}

		used[i] = true;
		
		if (cursum + nums[i] == target)
		{
			ret = dfs(nums,numsSize,target,needfind - 1, 0,0,used);
		}
		else if (cursum + nums[i] < target)
		{
			ret = dfs(nums,numsSize,target,needfind, i+1,cursum + nums[i],used);
		}
		if (!ret)
		{
			used[i] = false;
		}
		else
		{
			return true;
		}
	}

	return false;
}

bool canPartitionKSubsets(int* nums, int numsSize, int k)
{
	int i = 0;
	int aver = 0,total = 0;
	int max = 0;
	bool result = false;
	int used[MAX_ARRY_NUM + 1] = {0};
	
	for (i = 0; i < numsSize; i++)
	{
		total += nums[i];
		if (nums[i] > max)
		{
			max = nums[i];
		}
	}
	aver = total / k;

	//printf("total:%d, k:%d, aver:%d, numsSize:%d\n", total, k, aver,numsSize);

	if (total < k 
	|| (total > k && 0 != total%k)
	|| (max > aver))
	{
		printf("disable, total:%d, k:%d, aver:%d\n", total, k, aver);
		return false;
	}

	result = dfs(nums,numsSize,aver,k,0,0,used);

	return result;

}
