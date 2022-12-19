### 解题思路
此处撰写解题思路

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init(int n, int *father)
{
	int i;

	for (i = 0; i < n; i++) {
		father[i] = i;
	}
}

int find(int x, int *father)
{
	if (x != father[x]) {
		father[x] = find(father[x], father);
	}

	return father[x];
}

void union_circle(int x, int y, int *father)
{
	int fx = find(x, father);
	int fy = find(y, father);

	if (fx != fy) {
		father[fx] = fy;
	}
}

static int **array;
static int *len_array;

void alloc_array(int size)
{
	int loop;
	array = (int **)malloc(size * sizeof(int *));

	len_array = malloc(sizeof(int) * size);
	memset(len_array, 0, sizeof(int) * size);
}

static char *source;

static int compare(const void *p1, const void *p2)
{
	return source[*(const int *)p1] - source[*(const int *)p2];
}

char *smallestStringWithSwaps(char *s, int **pairs, int pairsSize,
			      int *pairsColSize)
{
	int i;
	int len;
	int *father;
	int index;
	int *tmp;
	int j;
        char *ans;

	if (!s || !pairs || !pairsSize)
		return s;

	len = strlen(s);
	source = s;
	tmp = (int *)malloc(sizeof(int) * len);
        ans = (char *)malloc(len + 1);
        ans[len] = 0;
	father = (int *)malloc(len * sizeof(int));
	init(len, father);
	alloc_array(len);
	/* union biggger link to little */
	for (i = 0; i < pairsSize; i++) {
		if (pairs[i][0] < pairs[i][1]) {
			union_circle(pairs[i][1], pairs[i][0], father);
		} else {
			union_circle(pairs[i][0], pairs[i][1], father);
		}
	}
	for (i = 0; i < len; i++) {
		index = find(i, father);
		len_array[index]++;
	}

	for (i = 0; i < len; i++) {
                if (len_array[i]) {
                        array[i] = (int *)malloc(len_array[i] * sizeof(int));
                }
                len_array[i] = 0;
	}

	for (i = 0; i < len; i++) {
		index = find(i, father);
		/* set the index to array */
		array[index][len_array[index]] = i;
		len_array[index]++;
	}

	for (i = 0; i < len; i++) {
		if (len_array[i]) {
			/* tmp is sorted, array is orign, and origin index is from little to big */
			memcpy(tmp, array[i], len_array[i] * sizeof(int));
			qsort(tmp, len_array[i], sizeof(int), compare);
			for (j = 0; j < len_array[i]; j++) {
                                //printf("%c - %c\n",  source[array[i][j]], source[tmp[j]]);
                                ans[array[i][j]] = source[tmp[j]];
			}
		}
	}
	return ans;
}
```