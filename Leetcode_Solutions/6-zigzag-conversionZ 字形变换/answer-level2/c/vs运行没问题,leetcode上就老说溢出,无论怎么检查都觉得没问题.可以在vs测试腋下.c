# 代码如下 简单易懂


```
char * convert(char * s, int numRows){
	char s1[6][7];
	memset(s1, 0, sizeof(s1));	
	int i = 0;
	bool flag = true;
	int t = 0;
	char *s2;
	s2 = (char*)malloc(strlen(s)+1);
	memset(s2, 0, sizeof(s2));	
	while(t < strlen(s)){
		if(flag){
			for(i;i < numRows;i++){		
				s1[i][strlen(s1[i])] = s[t]; 
				t++;	
			}
			flag = false;

		}else{
			for(i-=2;i > 0; i--){
				s1[2][strlen(s1[2])] = s[t];
				t++;
			}
			flag = true;
		}
		if(t >= strlen(s)){
			break;
		}
	}
	for(int a = 0;a<numRows;a++){
		strcat(s2,s1[a]);
	}
	return s2;
}
```
	



