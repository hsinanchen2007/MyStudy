```
int helper(int smaller, int bigger)
{
  if(smaller == 0) return 0;
  else if(smaller == 1) return bigger;

  if(smaller & 1) return bigger + multiply(smaller - 1, bigger);

  int half = multiply(smaller >> 1, bigger);
  return half + half;
}

int multiply(int A, int B){

  // distinguish the smaller and bigger could
  // make sure the smaller one will be handled recursively
  int smaller = A < B ? A : B;
  int bigger = A > B ? A : B;

  return helper(smaller, bigger);
}
```
