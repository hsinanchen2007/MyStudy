```
void backTrace(char *S, char *path, char *visited, int len, int depth, char **ret, int *returnSize)
{
  if(depth == len)
  {
    int retIndex = (*returnSize)++;
    ret[retIndex] = malloc(len + 1);
    memcpy(ret[retIndex], path, len + 1);
    return;
  }

  for(int i = 0; i < len; i++)
  {
    if(visited[i]) continue;

    visited[i] = 1;
    path[depth] = S[i];
    backTrace(S, path, visited, len, depth + 1, ret, returnSize);
    visited[i] = 0;
  }
}

int factorialTail(int pre, int n)
{
  if(n <= 1) return pre;

  return factorialTail(pre * n, n - 1);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** permutation(char* S, int* returnSize)
{
  int len = strlen(S);
  int retSize = factorialTail(1, len);
  char **ret = calloc(retSize, sizeof(char *));

  char *path = malloc(len + 1);
  path[len] = 0;
  char *visited = malloc(len + 1);
  memset(visited, 0, len + 1);

  *returnSize = 0;
  backTrace(S, path, visited, len, 0, ret, returnSize);

  assert(*returnSize == retSize);

  return ret;
}

```
