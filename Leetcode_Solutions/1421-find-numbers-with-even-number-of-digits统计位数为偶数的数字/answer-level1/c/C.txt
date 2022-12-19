int findNumbers(int* nums, int numsSize){
    int t,q=0,result=0;
    for (int i = 0; i <numsSize; i++)
	{
		t = nums[i];
		if (t / 10 == 0)continue;
		do
		{
			t = t / 10;
			q++;

		} while (t!=0);
		if (q % 2 == 0)
			result++;
            q=0;
	}
    return result;
}