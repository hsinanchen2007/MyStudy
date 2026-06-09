### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int pre[1000000];
int findRoot(int point, int kill) {
	int root = point;
	while (pre[root] != 0) {
		if (pre[root] == kill) {//要杀死的进程是你的长辈
			return true;
		}
        root=pre[root];
	}
	return false;
}
int* killProcess(int* pid, int pidSize, int* ppid, int ppidSize, int kill, int* returnSize) {
	for (int i = 0; i < pidSize; i++) {
		pre[pid[i]] = ppid[i];//辈分初始化
	}
	int* res = (int*)malloc(sizeof(int)*ppidSize);
	int top = 0;
    res[top++] = kill;
	for (int i = 0; i < ppidSize; i++) {
		if (findRoot(pid[i],kill)) {//要杀死的进程是不是你的长辈 是就添加
			res[top++] = pid[i];
		}
	}
	*returnSize = top;
	return res;
}
```