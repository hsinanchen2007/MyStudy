```
bool isOneBitCharacter(int* bits, int bitsSize){
if(bits[bitsSize-1]==1)
    return 0;
  for(int i=2;i<=bitsSize;i++){
      if(bits[bitsSize-i]==0&&i%2==0)
          return 1;
      else if(bits[bitsSize-i]==0&&i%2==1)
          return 0;
  }
    if(bitsSize%2==0)
        return 0;
    else 
        return 1;
}

```