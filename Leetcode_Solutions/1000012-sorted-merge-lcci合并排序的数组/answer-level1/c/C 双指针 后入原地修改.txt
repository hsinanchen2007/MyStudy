```
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
  
  assert(BSize == n);
  assert(ASize == n + m);
  
  int *ACur = A + m - 1;
  int *BCur = B + n - 1;
  
  int *cur = A + ASize - 1;
  
  while(cur >= A )
  {
    int num;
    
    // assert(ACur >= A || BCur >= B);
    
    if(ACur >= A && BCur >= B)
    {
      if(*ACur > *BCur) num = *ACur--;
      else              num = *BCur--;
    }
    else if(ACur >= A)  num = *ACur--;
    else                num = *BCur--;
    
    *cur-- = num;
  }
}
```
