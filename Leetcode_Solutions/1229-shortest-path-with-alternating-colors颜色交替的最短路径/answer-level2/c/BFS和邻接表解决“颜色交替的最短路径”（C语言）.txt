### 解题思路

问题的难点在于，邻接表分红和蓝，两次遍历后寻找最小路径；

同时节点也分红和蓝，用于记录不同的访问路标（是否访问过）。

解法思路清晰，编码有些冗余

### 代码

```c
#define MMIN(a, b)			((a) < (b)? (a) : (b))

#define ID_SIZE		100
#define QUE_SIZE	10000

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct _info_st
{
	int id[ID_SIZE];
	int cnt;
}info_st;

int que0_[QUE_SIZE];
int que1_[QUE_SIZE];

int *que0;
int *que1;

//【算法思路】BFS+邻接表。使用邻接表描述红色和蓝色有向图，从每个节点进行bfs遍历，获得结果。结果遍历两遍，红色开始和蓝色开始。
// flags表示的节点也分红蓝
int* shortestAlternatingPaths(int n, int** red_edges, int red_edgesSize, int* red_edgesColSize, int** blue_edges, int blue_edgesSize, int* blue_edgesColSize, int* returnSize){
	info_st *ired = (info_st *)calloc(n, sizeof(info_st));
	info_st *iblue = (info_st *)calloc(n, sizeof(info_st));

	for(int i = 0; i < red_edgesSize; i++)
	{
		int id = red_edges[i][0];
		ired[id].id[ ired[id].cnt++ ] = red_edges[i][1];
	}

	for(int i = 0; i < blue_edgesSize; i++)
	{
		int id = blue_edges[i][0];
		iblue[id].id[ iblue[id].cnt++ ] = blue_edges[i][1];
	}
/*
	for(int i = 0; i < n; i++)
	{
		printf("[");
		for(int j = 0; j < ired[i].cnt; j++)
		{
			printf("%d  ", ired[i].id[j]);
		}
		printf("]   ");
	}
	printf("\n");

	for(int i = 0; i < n; i++)
	{
		printf("[");
		for(int j = 0; j < iblue[i].cnt; j++)
		{
			printf("%d  ", iblue[i].id[j]);
		}
		printf("]   ");
	}
	printf("\n");
*/
	int *res = (int *)calloc(n, sizeof(int));

	for(int i = 1; i < n; i++)
	{
		int min_step = INT_MAX;

		//遍历下一个红色开始
		//红色0，蓝色1
		int color = 0;

		int *rflags = (int *)calloc(n, sizeof(int));
		int *bflags = (int *)calloc(n, sizeof(int));

		que0 = que0_;
		que1 = que1_;

		int qsize0 = 0;
		int qsize1 = 0;

		que0[qsize0++] = 0;
		
		int *flags = bflags;
		flags[0] = 1;

		bool find = false;

		int tar = i;
		
		int step = 0;

		while(qsize0 > 0)
		{
			step++;

			//选择的是下一个节点和边
			info_st *cinfo = (color == 0)? ired : iblue;
			flags = (color == 0)? rflags : bflags;

			for(int j = 0; j < qsize0; j++)
			{
				int id = que0[j];

				for(int k = 0; k < cinfo[id].cnt; k++)
				{
					int nid = cinfo[id].id[k];

					//跳出
					if(nid == tar)
					{
						find = true;
						break;
					}

					if(flags[nid] == 0)
					{
						que1[qsize1++] = nid;
						flags[nid] = 1;
					}
				}

				//跳出
				if(find == true)
				{
					break;
				}
			}

			//跳出
			if(find == true)
			{
				break;
			}

			int *tmpq = que0;
			que0 = que1;
			que1 = tmpq;

			qsize0 = qsize1;
			qsize1 = 0;

			color = (color == 0)? 1 : 0;
		}

		if(find == true)
		{
			min_step = MMIN(min_step, step);
		}

		//遍历下一个蓝色开始
		//红色0，蓝色1
		color = 1;

		rflags = (int *)calloc(n, sizeof(int));
		bflags = (int *)calloc(n, sizeof(int));

		que0 = que0_;
		que1 = que1_;

		qsize0 = 0;
		qsize1 = 0;

		que0[qsize0++] = 0;

		flags = rflags;
		flags[0] = 1;

		find = false;

		//tar = i;

		step = 0;

		while(qsize0 > 0)
		{
			step++;

			info_st *cinfo = (color == 0)? ired : iblue;
			flags = (color == 0)? rflags : bflags;

			for(int j = 0; j < qsize0; j++)
			{
				int id = que0[j];

				for(int k = 0; k < cinfo[id].cnt; k++)
				{
					int nid = cinfo[id].id[k];

					//跳出
					if(nid == tar)
					{
						find = true;
						break;
					}

					if(flags[nid] == 0)
					{
						que1[qsize1++] = nid;
						flags[nid] = 1;
					}
				}

				//跳出
				if(find == true)
				{
					break;
				}
			}

			//跳出
			if(find == true)
			{
				break;
			}

			int *tmpq = que0;
			que0 = que1;
			que1 = tmpq;

			qsize0 = qsize1;
			qsize1 = 0;

			color = (color == 0)? 1 : 0;
		}

		if(find == true)
		{
			min_step = MMIN(min_step, step);
		}

		if(min_step == INT_MAX)
		{
			res[i] = -1;
		}
		else
		{
			res[i] = min_step;
		}
	}

	*returnSize = n;
	return res;
}
```