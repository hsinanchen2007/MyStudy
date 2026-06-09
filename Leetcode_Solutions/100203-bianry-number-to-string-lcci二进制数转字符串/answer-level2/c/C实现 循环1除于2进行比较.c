```
char* printBin(double num){

  if(num <= 0 || num >= 1) return "ERROR";

  #define MAX_STRING_LEN 33

  char *ret = malloc(MAX_STRING_LEN + 1);
  memset(ret, 0, MAX_STRING_LEN + 1);
  strcpy(ret, "0.");

  char *cur = ret + strlen(ret);
  double dividedOne = 1.0;

  while(cur < ret + MAX_STRING_LEN && num > 0)
  {
    dividedOne /= 2.0;

    if(num >= dividedOne)
    {
      *cur++ = '1';
      num -= dividedOne;
    }
    else *cur++ = '0';
  }

  if(num > 0) return "ERROR";

  return ret;
}
```
