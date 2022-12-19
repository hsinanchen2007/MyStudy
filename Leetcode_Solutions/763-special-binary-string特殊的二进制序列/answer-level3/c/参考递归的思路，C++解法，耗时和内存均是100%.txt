void sortS(char *S, int pos, int begain, int *num)
{
	int i = num[pos];
	int j = num[begain];
	int m = pos - i + 1;
	int n = begain - j + 1;
	char tmp[51] = { 0 };
	int tmpNum[50] = { 0 };
	if (pos == begain)
	{
		return;
	}
	strncpy(tmp + m, S + m, begain - m + 1);
	strncpy(S + m, tmp + n, j);
	strncpy(S + j + m, tmp + m, n - m);

	memcpy(tmpNum + m, num + m, (begain - m + 1)*sizeof(int));
	memcpy(num + m, tmpNum + n, j*sizeof(int));
	memcpy(num + j + m, tmpNum + m, (n - m)*sizeof(int));
	return;
}

void MSort(char *S, int begain, int end, int *num)
{
	int i = begain;
	int j = 0;
	int iPos = 0;
	int jPos = 0;
	int cnt = 0;
	int pos = 0;
	int flag = 0;
	int aim = 0;
	int tmp = 0;
	if (end < begain)
	{
		return;
	}
	for (; i <= end; i++)
	{
		if ('0' == S[i])
		{
			cnt--;
		}
		else
		{
			cnt++;
		}
		if (0 == cnt)
		{
			num[i] = i - begain + 1;
			MSort(S, begain + 1, i - 1, num);
			flag = 0;
			for (j = begain - 1; j >= 0; j--)
			{
				if (num[j] == 0)
				{
					break;
				}				
				//aim = begain - num[j];
				tmp = 0;
				for (iPos = begain+1, jPos = j - num[j] + 2; iPos<i && jPos<j; iPos++, jPos++)
				{
					if (S[iPos] > S[jPos])
					{
						flag = 1;
						aim = j;
						break;
					}
					else if(S[iPos] < S[jPos])
					{
						tmp = 1;
						break;
					}
				}
				if (tmp == 0)
				{
					if (iPos < i)
					{
						flag = 1;
						aim = j;						
					}
					j = j - num[j] + 1;
					continue;
				}
				else
				{
					break;
				}
			}
			if (flag == 1)
			{
				sortS(S, aim, i, num);
			}
			begain = i + 1;
		}
	}
}

char * makeLargestSpecial(char * S)
{
	int num[50] = { 0 };
	int length = strlen(S);
	MSort(S, 0, length - 1, num);
	return S;
}

