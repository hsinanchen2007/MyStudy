### 解题思路
对于C解决此题的难点在于，如何处理字串结果。

根据题目反推，结果需要按照频率和字典序进行排序，可以构造qsort的compare函数实现，但要求结果存在连续内存中；

如果将结果存在连续内存，则不能构造链表实现hash表对查找加速。

但是可以使用字串hash，对比较过程加速。

按照这个思路实现，效率满足要求。

![image.png](https://pic.leetcode-cn.com/d99c4b529bf0e3b2ad24291314868e99836895cee293877a01fc403ae018d6ff-image.png)



### 代码

```c

#define QUE_SIZE	10000
#define RES_SIZE	10000

#define HASH_BASE	131

typedef long long ll_t;

typedef struct _info_st
{
	char vid[10];
	int cnt;
	ll_t ha;
}info_st;

char *res[RES_SIZE];

int que0_[QUE_SIZE];
int que1_[QUE_SIZE];

int *que0;
int *que1;

ll_t hash(char *s)
{
	int slen = strlen(s);

	ll_t ha = 0;

	for(int i = 0; i < slen; i++)
	{
		ha = ha * HASH_BASE + s[i];
	}

	return ha;
}

int compare(const void *a, const void *b)
{
	if((*(info_st *)a).cnt != (*(info_st *)b).cnt)
	{
		return (*(info_st *)a).cnt - (*(info_st *)b).cnt;
	}
	else
	{
		return strcmp((*(info_st *)a).vid, (*(info_st *)b).vid);
	}
}

//【算法思路】BFS+HASH+qsort。
// 1.先利用广度遍历，获得朋友id；
// 2.遍历所有id中的字串，建立一个信息队列；
// 3.使用qsort对信息队列进行排序；
// 4.将排序结果进行输出
char ** watchedVideosByFriends(char *** watchedVideos, int watchedVideosSize, int* watchedVideosColSize, int** friends, int friendsSize, int* friendsColSize, int id, int level, int* returnSize){
	int *flags = (int *)calloc(friendsSize, sizeof(int));

	que0 = que0_;
	que1 = que1_;

	int qsize0 = 0;
	int qsize1 = 0;

	que0[qsize0++] = id;
	flags[id] = 1;

	int cnt = 0;
	bool reach = false;

	while(qsize0 > 0)
	{
		if(cnt == level)
		{
			reach = true;
			break;
		}

		for(int i = 0; i < qsize0; i++)
		{
			int id = que0[i];

			for(int j = 0; j < friendsColSize[id]; j++)
			{
				int fid = friends[id][j];

				if(flags[fid] == 0)
				{
					que1[qsize1++] = fid;

					flags[fid] = 1;
				}
			}
		}

		int *tmpq = que0;
		que0 = que1;
		que1 = tmpq;

		qsize0 = qsize1;
		qsize1 = 0;

		cnt++;
	}

	if(reach == false)
	{
		*returnSize = 0;
		return NULL;
	}
/*
	//que0为对应id
	for(int i = 0; i < qsize0; i++)
	{
		printf("%d  ", que0[i]);
	}
	printf("\n");
*/
	info_st *info = (info_st *)calloc(RES_SIZE, sizeof(info_st));

	int isize = 0;

	for(int i = 0; i < qsize0; i++)
	{
		int id = que0[i];

		for(int j = 0; j < watchedVideosColSize[id]; j++)
		{
			//在结果中寻找符合的字串，没有就加入到尾部
			ll_t ha = hash(watchedVideos[id][j]);

			int loop = isize;
			bool find = false;
			for(int k = 0; k < loop; k++)
			{
				if(info[k].ha == ha)
				{
					info[k].cnt++;
					
					find = true;
					break;
				}
			}

			if(find == false)
			{
				strcpy(info[isize].vid, watchedVideos[id][j]);
				info[isize].cnt = 1;
				info[isize].ha = ha;
				isize++;
			}
		}
	}
/*
	for(int i = 0; i < isize; i++)
	{
		printf("%s , %d , %lld | ", info[i].vid, info[i].cnt, info[i].ha);
	}
	printf("\n");
*/
	qsort(info, isize, sizeof(info_st), compare);

	for(int i = 0; i < isize; i++)
	{
		res[i] = info[i].vid;
	}

	*returnSize  = isize;
	return res;
}
```