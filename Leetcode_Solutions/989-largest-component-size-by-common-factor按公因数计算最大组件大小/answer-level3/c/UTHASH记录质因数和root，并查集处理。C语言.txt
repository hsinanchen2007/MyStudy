### 解题思路
UTHASH记录质因数和root，并查集处理。C语言。

### 代码

```c
typedef struct {
	int prime;
	int root;
	UT_hash_handle hh;
}primeNode;

int *rootArray;
primeNode *head;

int findRoot(int child) {
	int root = child;
	int temp;

	while(root != rootArray[root]) {
		root = rootArray[root];
	}

	while (root != rootArray[child]) {
		temp = rootArray[child];
		rootArray[child] = root;
		child = temp;
	}

	return root;
}

void unionRoot(int A, int B) {
	int rootA = findRoot(A);
	int rootB = findRoot(B);

	if (rootA <= rootB) {
		rootArray[rootB] = rootA;
	} else {
		rootArray[rootA] = rootB;
	}
}

void addPrimeElement(int prime, int index) {
	primeNode *fnd, *new;
	HASH_FIND(hh, head, &prime, sizeof(int), fnd);
	//printf("Add prime:%d ", prime);
	if (NULL == fnd) {
		new = (primeNode *)calloc(1, sizeof(primeNode));
		new->prime = prime;
		new->root = index;
		HASH_ADD(hh, head, prime, sizeof(int), new);
		//printf("successfully\n");
		return;
	}
	//printf(", but already exist\n");
	unionRoot(index, fnd->root);
}

void freeHashData(void) {
	primeNode *fnd, *new;
	HASH_ITER(hh, head, fnd, new) {
		HASH_DEL(head, fnd);
		free(fnd);
	}
}

int cmpRoot(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}
int largestComponentSize(int* A, int ASize){
	int i, j, tmp, prePrime, ret;

	rootArray = (int *)calloc(ASize, sizeof(int));
	for (i = 0; i < ASize; i++) {
		rootArray[i] = i;
	}

	for (i = 0; i < ASize; i++) {
		tmp = A[i];
		prePrime = 0;
		//printf("Element:%d\n",tmp);
		for (j = 2; j <= sqrt(tmp); j++) {
			while(tmp != j) {
				if(tmp % j == 0) {
					if (prePrime != j) {
						prePrime = j;
						addPrimeElement(j, i);
					}
					//printf("%d*",j);
					tmp = tmp / j;
				}else {
					break;
				}
			}
		}
		if (prePrime != tmp) {
			addPrimeElement(tmp, i);
		}
	}

	for (i = 0; i < ASize; i++) {
		j = findRoot(i);
	}

	qsort(rootArray, ASize, sizeof(int), cmpRoot);
	prePrime = rootArray[0] - 1;
	j = 0;
    ret = 0;
	for (i = 0; i < ASize; i++) {
		if (rootArray[i] != prePrime) {
			prePrime = rootArray[i];
			j = 1;
			continue;
		}

		j++;
		ret = (ret > j) ? ret : j;
	}
	ret = (ret > j) ? ret : j;

	freeHashData();
	free(rootArray);
	return ret;
}

```