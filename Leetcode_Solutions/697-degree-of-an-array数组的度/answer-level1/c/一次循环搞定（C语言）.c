50000个结构体打印出来只有580多KB，但是运行结果总是显示60多MB开销，将malloc换成栈上的临时变量即可将内存跑分降下来。


int findShortestSubArray(int* nums, int numsSize)
{
	int i = 0;
	int tmp = 0,templen;
	int maxnums = 0;
	int minlen = 0xffffff;
	#define MAX_VAL (50000)

	typedef struct _note
	{
		int nums;
		int start;
		int end;
	}NOTE;

	NOTE Note[MAX_VAL];// = {0};NULL;
	
#if 0 /*使用malloc的方式会导致内存开销跑出来60多MB*/
	Note = (NOTE*)malloc(sizeof(NOTE)*MAX_VAL);
	if (NULL == Note)
	{
		printf("malloc err\n");
		return 0;
	}
#endif
	memset(Note, 0, sizeof(NOTE)*MAX_VAL);

	printf("mallc size %ld KB\n", (sizeof(NOTE)*MAX_VAL)/1024);

	for (i = 0; i < numsSize; i++)
	{
		tmp = nums[i];

		if (0 >= Note[tmp].nums)
		{
			Note[tmp].start = i;
			Note[tmp].end = i;
		}
		else
		{
			Note[tmp].end = i;
		}
		Note[tmp].nums++;
		if (Note[tmp].nums > maxnums)
		{
			templen = Note[tmp].end - Note[tmp].start + 1;		
			maxnums = Note[tmp].nums;
			minlen = templen;
		}
		else if (Note[tmp].nums == maxnums)
		{
			templen = Note[tmp].end - Note[tmp].start + 1;		
			if (minlen > templen)
			{
				minlen = templen;
			}
		}
		else
		{
			//do nothing
		}
	}

//	free(Note);

	return minlen;

}
