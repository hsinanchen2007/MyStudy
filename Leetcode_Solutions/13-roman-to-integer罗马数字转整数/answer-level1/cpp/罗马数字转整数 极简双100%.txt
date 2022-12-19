

```c
int romanToInt(char * s){
	int sum=0;
	while(*s!='\0'){
		if(*s=='I') (*(s+1)=='V'||*(s+1)=='X')?(sum-=1):(sum+=1); 
		if(*s=='V') sum+=5;
		if(*s=='X') (*(s+1)=='L'||*(s+1)=='C')?(sum-=10):(sum+=10);
		if(*s=='L') sum+=50;
		if(*s=='C') (*(s+1)=='D'||*(s+1)=='M')?(sum-=100):(sum+=100);
		if(*s=='D') sum+=500;
		if(*s=='M') sum+=1000;	
		s++;			
	}		
    return sum;
}
```