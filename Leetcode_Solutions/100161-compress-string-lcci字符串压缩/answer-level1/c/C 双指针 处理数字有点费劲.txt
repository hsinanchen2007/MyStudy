```

void reverse(char *s)
{
  int len = strlen(s);

  char *front = s;
  char *rear = s + len - 1;

  while(front < rear)
  {
    char tmp = *front;
    *front = *rear;
    *rear = tmp;
    front++;
    rear--;
  }
}

char* compressString(char* S){

  int len = strlen(S);

  char *ret = malloc(2 * len + 1);
  memset(ret, 0, 2 * len + 1);
  int retSize = 0;

  char *left = S;
  char *right = S + 1;
  int count = 1;

  while(right <= S + len)
  {
    if(*right == 0 || *left != *right)
    {
      ret[retSize++] = *left;

      // append the count
      char numBuf[6];
      memset(numBuf, 0, 6);
      while(count)
      {
        numBuf[strlen(numBuf)] = count % 10 + '0';
        count /= 10;
      }
      reverse(numBuf);

      strcat(ret + retSize, numBuf);
      retSize += strlen(numBuf);

      count = 1;
      left = right;
    }
    else count++;

    right++;
  }

  if(retSize < len) return ret;
  else              return S;
}
```
