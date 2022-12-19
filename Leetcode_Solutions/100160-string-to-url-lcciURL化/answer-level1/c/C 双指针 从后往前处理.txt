```
char* replaceSpaces(char* S, int length){
  
  int sLen = strlen(S);
  char *sCur = S + sLen - 1;
  char *cur = S + length - 1;

  while(cur >= S)
  {
    if(*cur != ' ')
    {
      *sCur = *cur;
    }
    else
    {
      sCur -= 2;
      sCur[0] = '%';
      sCur[1] = '2';
      sCur[2] = '0';
    }
    
    cur--;
    sCur--;
  }
  
  return sCur + 1;
}
```
