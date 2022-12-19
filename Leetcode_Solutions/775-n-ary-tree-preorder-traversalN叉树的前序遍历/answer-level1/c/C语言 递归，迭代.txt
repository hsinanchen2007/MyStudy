```c
/**
 * 递归
 **/ 
#define MAX_SIZE 10240
void visit(struct Node* root, int* result, int* returnSize) {
  if (root)
    for (int i = 0; i < root->numChildren; i++) {
      result[(*returnSize)++] = root->children[i]->val;
      visit(root->children[i], result, returnSize);
    }
}
int* preorder(struct Node* root, int* returnSize) {
  int i, *result = (int*)calloc(MAX_SIZE, sizeof(int));
  *returnSize = 0;
  if (root == NULL) return result;
  result[(*returnSize)++] = root->val;
  visit(root, result, returnSize);
  return result;
}
```

```c
/**
 * 迭代
 **/ 
#define MAX_SIZE 10240
int* preorder(struct Node* root, int* returnSize) {
  int i, top = -1, *result = (int*)calloc(MAX_SIZE, sizeof(int));
  struct Node *p, **stack = (char**)malloc(sizeof(struct Node*) * MAX_SIZE);
  *returnSize = 0;
  if (root == NULL) return result;
  stack[++top] = root;
  while (top != -1) {
    p = stack[top--];
    result[(*returnSize)++] = p->val;
    // 从最后一个孩子开始入栈
    for (i = p->numChildren - 1; i >= 0; i--)
      stack[++top] = p->children[i];
  }
  return result;
}
```
