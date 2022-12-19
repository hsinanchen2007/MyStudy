![1.png](https://pic.leetcode-cn.com/483090472421749bc4286e43717c04f8ed22b47f701febb9b8955b324213396e-1.png)

### 解题思路
1、遍历一次数组的第一个元素。找出不信任任何人的编号res；如果所有人都信任了其他人，返回-1；
2、遍历一次数组的第二个元素。如果N-1个人信任res，则返回res,否则返回-1.

### 代码

```c
int findJudge(int N, int** trust, int trustSize, int* trustColSize){
	int i, res = 0;
	int *map = (int*)calloc(N + 2, sizeof(int));
	for (i = 0; i < trustSize; i++)
		map[trust[i][0]]++;
	for (i = 1; i <= N; i++)
		if (!map[i]){
			res = i;
            break;
        }
	if (!res)
		return -1;                              //至此，第一步结束
	memset(map, 0, sizeof(int)*(N + 2));
	for (i = 0; i < trustSize; i++)
		map[trust[i][1]]++;
	if (map[res] == N - 1)
		return res;
	return -1;
}
```