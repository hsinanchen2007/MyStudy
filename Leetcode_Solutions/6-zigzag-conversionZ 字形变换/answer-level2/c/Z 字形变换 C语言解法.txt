感觉还好~
char * convert(char * s, int numRows){
     int len=strlen(s);
    int t=2*(numRows-1);
    char * s1 = (char *) calloc(len+1, sizeof(char));
    int k=0,j=0,i;
    if(numRows == 1)
    {
        return s;
    }
    else{
    	while(j<numRows){
    		for(i=0;i<len;i++){
    			if(i%t==j && (j==0 || j==t)){
    				 s1[k]=s[i];
                    	k++;
				}               
            else if(i%t==j || i%t==t-j && (j!=0 || j!=t)){
            		s1[k]=s[i];
                    	k++;
				}   
			}
			j+=1;
		}
		return s1;
	}
}