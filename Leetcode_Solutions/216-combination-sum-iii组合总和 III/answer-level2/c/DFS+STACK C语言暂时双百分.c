```
#define MAX_NUM 	100

#define STACK_SIZE 	100
int g_stack[STACK_SIZE];
int g_stack_size;

void STACK_Init(void)
{
	g_stack_size = 0;
}

bool STACK_Push(int num)
{
	if (g_stack_size < STACK_SIZE-1){
		g_stack[g_stack_size++] = num;
		return true;
	}
	return false;
}

bool STACK_Pop(void)
{
	if (g_stack_size > 0){
		g_stack_size--;
		return true;
	}
	return false;
}

bool STACK_GetMember(int **out, int *size)
{
	if (g_stack_size < 0){
		return false;
	}
	*size = g_stack_size;
	*out = (int*)malloc(g_stack_size*sizeof(int));
	memcpy(*out, g_stack, sizeof(int) * g_stack_size);
	return true;
}


void dfs(int start, int k, int layer, int target, int **ret, int *returnSize, int** returnColumnSizes)
{
	int i;
	if (layer == k) {
		if (target == 0){
			if (STACK_GetMember(&ret[*returnSize], &(*returnColumnSizes)[*returnSize]) == true) {
				/*printf("got it\n");
				for(i=0; i<(*returnColumnSizes)[*returnSize]; i++){
					printf("%d ", ret[*returnSize][i]);
				}
				printf("\n");*/
				(*returnSize)++;
			}
		}
		return;
	}
	for(i=start; i<10; i++) {
		if (target - i >= 0) {
			STACK_Push(i);
			dfs(i+1, k, layer+1, target-i, ret, returnSize, returnColumnSizes);
			STACK_Pop();
		}
	}
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes)
{
	int i;
	*returnSize = 0;
	int **ret = (int**)malloc(sizeof(int*)*MAX_NUM);
	*returnColumnSizes = (int*)malloc(sizeof(int)*MAX_NUM);

	for(i=1; i<10; i++) {
		if (n-i >= 0) {
			STACK_Push(i);
			dfs(i+1, k, 1, n-i, ret, returnSize, returnColumnSizes);
			STACK_Pop();
		}
	}
	return ret;
}
```
