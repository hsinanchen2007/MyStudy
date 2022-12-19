```
#define MAX_26 26
#define MAX_500 500

typedef struct MyStruct
{
	int nums;
	char mark;
} HASH;

static int comp(const void *a, const void *b)
{
	return ((HASH *)b)->nums - ((HASH *)a)->nums;
}
char *reorganizeString(char *S)
{
	HASH hash[MAX_26] = {0};
	int Slen = strlen(S);
	char *ans = (char *)calloc(MAX_500 * MAX_500, sizeof(char));

	for (int i = 0; i < Slen; i++)
	{
		hash[S[i] - 'a'].nums++;
		hash[S[i] - 'a'].mark = S[i];
	}
	char map[MAX_500][MAX_500] = {{0}};

	qsort(hash, MAX_26, sizeof(HASH), comp);

	int m = 0;
	int maxRow = hash[0].nums;
	for (int i = 0; i < MAX_500; i++)
	{
		for (int j = 0; j < maxRow; j++)
		{
			if (m < MAX_26 && hash[m].nums > 0)
			{
				map[j][i] = hash[m].mark;
				hash[m].nums--;
			}
			if (m < MAX_26 && hash[m].nums == 0)
			{
				m++;
			}
		}
	}

	int flag = 0;
	int index = 0;
	for (int i = 0; i < MAX_500; i++)
	{
		if (flag > 1)
		{
			return (char *)"";
		}
		if (map[i][0] != 0 && map[i][1] == 0)
		{
			flag++;
		}
		index += snprintf(ans + index, MAX_500 * MAX_500 - index, "%s", map[i]);
	}
	return ans;
}
```
