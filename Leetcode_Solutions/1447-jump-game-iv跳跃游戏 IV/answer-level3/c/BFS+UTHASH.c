### 解题思路
此处撰写解题思路

### 代码

```c
struct PosNode {
	int pos;
	struct PosNode *next;
};

struct HashSt
{
	int iKey;
	struct PosNode *ln;
	UT_hash_handle hh;
};

struct HashSt *users = NULL;

void AddUser(int myKey, int pos) {
	struct HashSt *s = NULL;

	struct PosNode *temp = NULL;

	HASH_FIND_INT(users, &myKey, s); /* myKey already in the hash? */
	if (s == NULL) {
		s = (struct HashSt *)malloc(sizeof(struct HashSt));
		s->iKey = myKey;
		s->ln = (struct PosNode*)malloc(sizeof(struct PosNode));
		s->ln->pos = pos;
		s->ln->next = NULL;
		HASH_ADD_INT(users, iKey, s); /* ikey: name of key field */
	} else {
		temp = (struct PosNode*)malloc(sizeof(struct PosNode));
		temp->pos = pos;
		temp->next = s->ln->next;
		s->ln->next = temp;
	}

}

struct HashSt *FindUser(int mykey) {
	struct HashSt *s = NULL;

	HASH_FIND_INT(users, &mykey, s); /* s: output pointer */
	return s;
}

void DeleteUser(struct HashSt *user) {
	HASH_DEL(users, user); /* user: pointer to deletee */
	free(user);
}

void DeleteAll() {
	struct HashSt *current_user, *tmp;
	struct PosNode *tt = NULL;
	struct PosNode *temp = NULL;
	HASH_ITER(hh, users, current_user, tmp) {
		tt = current_user->ln;
		while (temp != NULL) {
			tt->next = temp->next;
			free(temp);
			temp = tt->next;
		}
		free(tt);
		HASH_DEL(users,current_user); /* delete it (users advances to next) */
		free(current_user); /* free it */
	}
}

struct BfsNode {
	int pos;
	int step;
	struct BfsNode *listN;
};

struct BfsNode *AddBFSNode(struct BfsNode *tail, int pos, int step)
{
	struct BfsNode *temp = (struct BfsNode *)malloc(sizeof(struct BfsNode));
	temp->pos = pos;
	temp->step = step;
	temp->listN = NULL;

	tail->listN = temp;

	return temp;
}

void DeleteBFSNode(struct BfsNode *target)
{
	free(target);
}

void DeleteAllBFSNode(struct BfsNode *target)
{
	struct BfsNode *temp = target;
	struct BfsNode *next = NULL;

	while (temp != NULL) {
		next = temp->listN;
		free(temp);
		temp = next;
	}
}

int BFS(int *arr, int arrSize)
{
	struct BfsNode *head = (struct BfsNode *)malloc(sizeof(struct BfsNode));
	head->pos = 0;
	head->step = 0;
	head->listN = NULL;

	struct BfsNode *target = head;
	struct BfsNode *tail = head;
	struct BfsNode *tNext = target;

	int *visit = (int *)malloc(arrSize * sizeof(int));
	memset(visit, 0, arrSize * sizeof(int));

	int position;
	int value;
	int temp;
	struct HashSt *ts = NULL;
	struct PosNode *tt = NULL;
	while (target != NULL) {
		position = target->pos;
		value = arr[position];
		visit[position] = 1;
		printf("loop position %d \n", position);

		temp = position - 1;
		if (temp >= 0 && visit[temp] == 0) {
			tail = AddBFSNode(tail, temp, target->step + 1);
			visit[temp] = 1;
		}
		printf("temp %d \n", temp);

		temp = position + 1;
		if (temp == arrSize - 1) {
			temp = target->step + 1;
			DeleteAllBFSNode(target);
			return temp;
		}
		if (temp < arrSize && visit[temp] == 0) {
			tail = AddBFSNode(tail, temp, target->step + 1);
			visit[temp] = 1;
		}
		printf("temp %d \n", temp);

		ts = FindUser(value);
		if (ts == NULL) {
			continue;
		}
		tt = ts->ln;
		while (tt != NULL) {
			temp = tt->pos;
			if (temp == arrSize - 1) {
				temp = target->step + 1;
				DeleteAllBFSNode(target);
				return temp;
			}
			if (temp >= 0 && temp < arrSize && visit[temp] == 0) {
				tail = AddBFSNode(tail, temp, target->step + 1);
				visit[temp] = 1;
			}
			tt = tt->next;
			printf("bfs temp %d \n", temp);
		}
		printf("loop value %d \n", value);
		tNext = target->listN;
		DeleteBFSNode(target);
		target = tNext;
	}
	return -1;
}

int minJumps(int *arr, int arrSize) {
	printf("arrSize %d \n", arrSize);
	if (arrSize == 1) {
		return 0;
	}
	int i;
	struct HashSt *ts = NULL;
	struct PosNode *tt = NULL;
	struct PosNode *tNext = NULL;
	struct PosNode *temp = NULL;
	for (i = 0; i < arrSize; i++) {
		AddUser(arr[i], i);
	}

	printf("arrSize2 %d \n", arrSize);
	int ret = BFS(arr, arrSize);

	DeleteAll();//free hash list and the pos list node
	return ret;
}
```