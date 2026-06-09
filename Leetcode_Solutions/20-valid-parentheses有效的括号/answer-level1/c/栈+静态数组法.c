### 解题思路
此处撰写解题思路

### 代码

```c
bool isValid(char * s){
    char st[5000];int top=-1;
	for(int i=0;s[i]!='\0';i++){
		if(top==-1){
			st[++top]=s[i];continue;
		}
		char t=st[top];
		switch(t){
			case '(':if(s[i]==')'){top--;}else{st[++top]=s[i];}	break;
			case '[':if(s[i]==']'){top--;}else{st[++top]=s[i];}	break;
			case '{':if(s[i]=='}'){top--;}else{st[++top]=s[i];}	break;
			default: st[++top]=st[++top]=s[i];
		}
		
	}
	if(top!=-1){
		return 0;
	}else{
		return 1;
	}
}
```