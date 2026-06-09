```

bool oneEditAway(char* first, char* second){

  int len1 = strlen(first);
  int len2 = strlen(second);

  if(len1 == len2)
  {// replace case
    for(int i = 0; i < len1; i++)
    {
      if(first[i] != second[i])
      {
        first[i] = second[i];
        break;
      }
    }

    return strcmp(first, second) == 0;
  }
  else if(abs(len1 - len2) < 2)
  {// delete(insert) a character
    char *shortCur = first, *longCur = second;

    if(len1 > len2)
    {
      shortCur = second;
      longCur = first;
    }

    while(*shortCur)
    {
      if(*shortCur != *longCur)
      {
        longCur++;
        break;
      }

      shortCur++;
      longCur++;
    }

    if(*shortCur == 0) return 1;
    else return strcmp(shortCur, longCur) == 0;
  }

  return 0;
}

```
