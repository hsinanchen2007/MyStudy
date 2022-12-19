```
 bool isOneBitCharacter(int* bits, int bitsSize){
	
	int i;

	for(i = bitsSize - 2; i >= 0 && bits[i] != 0; i--);

	return (bitsSize - i)%2 == 0 ? true : false;
	
}
```
