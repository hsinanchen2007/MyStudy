```
bool dfs(int *A, int ASize, int target, int depth, int start)
{
  if(depth == 3) return 1;

  int curSum = 0;

  for(int i = start; i < ASize; i++)
  {
    curSum += A[i];

    if(curSum == target) 
      return dfs(A, ASize, target, depth + 1, i + 1);
  }

  return 0;
}


bool canThreePartsEqualSum(int* A, int ASize){

  int tarSum = 0;

  for(int i = 0; i < ASize; i++)
    tarSum += A[i];

  if(tarSum % 3) return 0;
  
  tarSum /= 3;

  return dfs(A, ASize, tarSum, 0, 0);
}
```
