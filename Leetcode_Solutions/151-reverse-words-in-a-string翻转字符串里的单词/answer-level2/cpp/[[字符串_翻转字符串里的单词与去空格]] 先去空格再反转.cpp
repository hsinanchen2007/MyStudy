只想到了常规做法
```c
void reverse(char *s,int sta,int en){
    char temp;
    while(sta<en){
        temp=s[sta];
        s[sta++]=s[en];
        s[en--]=temp;
    }
}
char * reverseWords(char * s){
	if(*s==NULL) return s;	  	 
	int lastvalid=-1;
	int preisblank=1;
	int i=0;
	while(s[i]!='\0'){
		if(s[i]!=' '){
			s[++lastvalid]=s[i];
			preisblank=0;
		}
		if(s[i]==' '&&!preisblank){
			s[++lastvalid]=s[i];
			preisblank=1;			
		}		
    	i++;
	}
	if(lastvalid==-1){
	    s[0]='\0';
	    return s;
	}
	int start=0,end;
	if(s[lastvalid]==' '){
		s[lastvalid]='\0';
		end=lastvalid-1;
	}else{
		s[lastvalid+1]='\0';
		end=lastvalid;
	}
	reverse(s,start,end);	
	i=0;
	while(i<=end){
		if(s[i]==' '){
	        reverse(s,start,i-1);
			start=i+1;
		}
		if(i==end) reverse(s,start,i);     		
	    	i++;
	}  
	return s;
}
```