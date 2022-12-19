struct data{
	char ch;
	int first;
	int end;
	int isvalid;
};


char * removeDuplicateLetters(char * s){    
    if(s == NULL) return NULL;
    
    char st = 'a';
    int i,j,k,m,n;
    int len = strlen(s);
    int sum = 0;
    int retlen = 0;
	int start = 0;
	struct data ret[26] = {0};
    char *src = (char *)malloc(sizeof(char) * (len+1));
    char *retout;
    int flag = 0;
	int index = 0;;
    
    //strcpy_s(src,len, s);
	for(i = 0;i<len;i++){
		src[i] = s[i];	
	}
    src[len] = 0;
    
    for(i=0;i<26;i++){
        for(j = 0;j<len;j++){
            if((st+i) == s[j]){
				ret[i].ch = s[j];
                ret[i].first = j;
				ret[i].isvalid = 1;
                sum++;
                break;
            }            
        }      
    } 

	for(i = 0;i<26;i++){
		for(j = len-1;j>=0;j--){
			if((st+i) == s[j]){
                ret[i].end = j;
                break;
            }  
		}
	}

	retout = (char *)malloc(sizeof(char) * (sum + 1));
	retout[sum] = 0;
	retlen = sum;
    k = 0;
	while(sum > 0){
		for(i = 0;i< 26;i++){
			flag = 0;
			if(ret[i].isvalid == 1){
				flag = 1;
				for(j = i+1;j<26;j++){
					if((ret[j].isvalid == 1) && (ret[j].end < ret[i].first)){
						flag = 0;	
						break;					
					}
				}
				if(flag == 1){
					retout[k++] = ret[i].ch;
					ret[i].isvalid = 0;
					sum--;

					//更新剩余字符串的fisrt
					for(m = 0;m<26;m++){
						if(ret[m].isvalid == 1)
						{
							for(n = ret[i].first + 1;n <len;n++ )
							{
								if((st+m) == s[n]){
									ret[m].first = n;
									break;
								} 
							}
						}					
					}
				}
			}
			if(flag == 1) break;
		}
	}
	    
    return retout;
}
