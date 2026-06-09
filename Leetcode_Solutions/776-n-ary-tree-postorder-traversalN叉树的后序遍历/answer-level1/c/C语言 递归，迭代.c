```c
/**
 * 递归
 **/
#define MAX_SIZE 10240
void visit(struct Node* root, int* result, int* returnSize) {
  if (root)
    for (int i = 0; i < root->numChildren; i++) {
      visit(root->children[i], result, returnSize);
      result[(*returnSize)++] = root->children[i]->val;
    }
}
int* postorder(struct Node* root, int* returnSize) {
  int i, *result = (int*)calloc(MAX_SIZE, sizeof(int));
  *returnSize = 0;
  if (root == NULL) return result;
  visit(root, result, returnSize);
  result[(*returnSize)++] = root->val;
  return result;
}
```

```c
/**
 * 迭代
 **/
#define MAX_SIZE 10240
void reverse(int* array, int arraySize) {
  for (int i = 0, j = arraySize - 1; i <= j; i++, j--) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}
int* postorder(struct Node* root, int* returnSize) {
  int i, top = -1, *result = (int*)calloc(MAX_SIZE, sizeof(int));
  struct Node* p;
  struct Node** stack = (char**)malloc(sizeof(struct Node*) * MAX_SIZE);
  *returnSize = 0;
  if (root == NULL) return result;
  stack[++top] = root;
  while (top != -1) {
    p = stack[top--];
    if (p) result[(*returnSize)++] = p->val;
    for (i = 0; i < p->numChildren; i++) {
      stack[++top] = p->children[i];
    }
  }
  reverse(result, *returnSize); //反转
  free(stack);
  return result;
}
```
