```
int firstUniqChar(char * s){
    
    int *b = (int*)calloc(128,sizeof(int));
    
	char* p = s;
	while(*p != '\0'){
		b[*(p++)]++;
	}
    p = s;
    int index = 0;
	while(*p != '\0'){
		if (b[*(p++)] == 1) {
            return index;
		}
        index++;
	}
    return -1;
}
```
