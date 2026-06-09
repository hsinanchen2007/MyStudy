
中间还是掉坑了 字符串拼接还是要注意 参看一下别人处理拼接的实现。

```

char* compressString(char* S){

  int lenS = strlen(S);

  char *newS = malloc(lenS * 2 + 1);
  memset(newS, 0, lenS * 2 + 1);

  int indexS = 0;
  int cnt = 0;

  int lenNewS = 0;

  while(indexS < lenS)
  {
    cnt++;

    if(S[indexS] != S[indexS + 1])
    {
      newS[lenNewS++] = S[indexS];

      // convert number to string and append to the end
      int numLen = sprintf(newS + lenNewS, "%d", cnt);
      lenNewS += numLen;
      cnt = 0;
    }

    indexS++;
  }

  return lenNewS < lenS ? newS : S;
}

```
