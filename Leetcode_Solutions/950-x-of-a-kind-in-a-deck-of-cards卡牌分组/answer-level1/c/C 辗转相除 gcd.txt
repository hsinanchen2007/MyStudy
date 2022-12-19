
click here

```
// continous divid method to calculate gcd
int gcd(int small, int big)
{  
  return small == 0 ? big : gcd(big % small, small); 
}

#define MAX_DECK  10000

bool hasGroupsSizeX(int* deck, int deckSize){

  if(deckSize <= 1) return 0;

  int map[MAX_DECK] = {0};

  for(int i = 0; i < deckSize; i++)
    map[deck[i]]++;

  int gcd_val = 0;

  for(int i = 0; i < MAX_DECK; i++)
    gcd_val = gcd(gcd_val, map[i]);

  return gcd_val > 1;
}
```
