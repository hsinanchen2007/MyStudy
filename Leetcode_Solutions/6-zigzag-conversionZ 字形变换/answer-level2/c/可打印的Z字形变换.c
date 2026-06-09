char *convert(char *s, int numRows){
	int len=0;
    char *sp = s;
	while( *(sp++) != '\0');
	len = sp-s;
	int clen = (len+3)/2;
	int count = clen * numRows;
	char *str = malloc( (count + 1) * sizeof(char));
	memset(str, 32, count);
	int f = 1;
	int j = 0;
	int k = 0;
	int r = 1;
	for(int i=0;i<len;i++){
		if ( r == 1 ){
			f = 1;
			k = 0;
		}
		if( r==numRows){
			f = -1;
			k = 1;
		}
		*(str+j) = *(s+i);
		j = j + f*clen + k;
		r+=f;
	}
	for(int i=1;i<numRows;i++){
		*(str+i*clen-1) = '\n';
	}
	*(str+count) = '\0';
	return str;
}