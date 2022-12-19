

```
bool isOneBitCharacter(int* bits, int bitsSize){
    for (int i = 0; i < bitsSize; ++i) {
        if (i == bitsSize-1) return (bits[i] ? false : true);
        if (bits[i]) ++i;        
    }
    return false;
}
```
