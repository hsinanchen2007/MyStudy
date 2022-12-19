```
int longestPalindrome(char * s){

  int map[128] = {0};

  while(*s) map[*s++]++;

  bool hasOddNum = false;

  int ret = 0;

  for(int i = 0; i < 128; i++)
  {
      if(map[i] % 2 == 0)
      { // even case
        ret += map[i];  
      }
      else
      { // odd case     
        hasOddNum = true; 
        ret += map[i] - 1;
      }
  }

  return ret + hasOddNum;
}
```
