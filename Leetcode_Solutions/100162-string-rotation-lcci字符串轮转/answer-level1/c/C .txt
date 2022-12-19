```
bool isFlipedString(char* s1, char* s2){
  
  if(strlen(s1) != strlen(s2)) return 0;
  
  // double copy the s1 to buffer
  char *s = malloc(strlen(s1) * 2 + 1);
  strcpy(s, s1);
  strcat(s, s1);
  
  // the fliped string s2 should be a sub-string of the doubled s1
  bool ret = strstr(s, s2) != NULL;

  free(s);

  return ret;
}
```
