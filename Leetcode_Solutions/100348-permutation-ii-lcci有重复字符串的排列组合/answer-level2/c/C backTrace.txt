```
void backTrace(char* S, int* returnSize, int len, int depth, char **ret, char *path, char *visited)
{
  if(depth == len)
  {
    int retIndex = (*returnSize)++;
    ret[retIndex] = malloc(len + 1);
    strcpy(ret[retIndex], path);
    return;
  }

  char duplicateMap[128] = {0};

  for(int i = 0; i < len; i++)
  {
    if(visited[i])          continue;   
    if(duplicateMap[S[i]])  continue;   // the letter has shown up at this position

    duplicateMap[S[i]] = 1;
    visited[i] = 1;
    path[depth] = S[i];
    backTrace(S, returnSize, len, depth + 1, ret, path, visited);
    visited[i] = 0;
  }
}

#define MAX_LEN 1000

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** permutation(char* S, int* returnSize){

  char **ret = calloc(MAX_LEN, sizeof(char *));
  int len = strlen(S);

  char path[10] = {0};
  char visited[10] = {0};

  *returnSize = 0;
  backTrace(S, returnSize, len, 0, ret, path, visited);

  return ret;
}


```
