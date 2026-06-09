```
int waysToStep(int n){

  long pre[] = {0, 1, 2, 4};

  if(n <= 3) return pre[n];

  long cur;

  for(int i = 4; i <= n; i++)
  {
    cur = (pre[1] + pre[2] + pre[3]) % 1000000007;
    pre[1] = pre[2];
    pre[2] = pre[3];
    pre[3] = cur;
  }

  return cur;
}
```
