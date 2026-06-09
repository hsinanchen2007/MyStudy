
char * longestCommonPrefix(char** strs, int strsSize){
    if(strsSize==0) return "";
    int i=0,count=0;
    char* s = *strs;
    while(*s!='\0'){
    	char tmp=*(*strs+count);
    	for(i=1;i<strsSize;i++){
    		if(*(*(strs+i)+count)!=tmp){
                *s='\0';
                return s-count;
            }
		}
		s++;
        count++;
	}
	return *strs;
}
```