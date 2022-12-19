class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
	
	unsigned short size = nums.size();
	if (size < 2)
		return false;
	for (unsigned short i = 0; i != size; ++i)
	{
		
		if ( nums[i] > 1000)
			continue;
        //初始化  确定方向
		unsigned short k = i;
		bool bForward = nums[k] < 0 ? false : true;
		unsigned short j;
		
		j = bForward ? ((k + nums[k]) % size) : ((k + size - ((-nums[k]) % size)) % size);
		nums[k] = i+1001;
		if ( nums[j] > 1000)
			continue;
		if (j == k)
			continue;
		//将访问过的置0，出现循环也就是重新走到元素为0的位置上。
		k = j;
		bool res = true;
		while (nums[j] != i+1001)
		{
            if (nums[j] > 1000)
            {
                res = false;
                break;
            }
			if ((nums[k] > 0) != bForward)
			{
				res = false;
				break;
			}
			j = bForward ? ((k + nums[k]) % size) : ((k + size - ((-nums[k]) % size)) % size);
			nums[k] = i+1001;
			if (j == k)
			{
				res = false;
				break;
			}
			k = j;
		}
		if (res)
			return true;
	}
	return false;
}
};