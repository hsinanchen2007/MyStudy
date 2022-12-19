
```
int candy(int* ratings, int ratingsSize){
	
	if(ratingsSize <= 0)
    {
        return 0;
    }

    int ret = 1, num = 1, pre = -1, num_pre = INT_MAX;
	
	for(int i = 1; i < ratingsSize; i++)
	{
		if(ratings[i] < ratings[i - 1])
		{
			num = 1;
			ret += num;
            if(i - pre < num_pre) //满足此条件时，递减序列长度小于递增序列，此时不需要增加峰值
            {
                ret += (i - pre - 1);
            }
            else
            {
                ret += (i - pre);
            }
			
		}
		else if (ratings[i] > ratings[i - 1])
		{
			ret += (++num);
			pre = i;
            num_pre = num;
		}
		else
		{
			return ret + candy((ratings + i), ratingsSize - i);
		}
	}
	
	return ret;
}
```
