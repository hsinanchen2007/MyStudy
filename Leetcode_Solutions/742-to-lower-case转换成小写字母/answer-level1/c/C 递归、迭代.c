递归
```
char * toLowerCase(char * str){
	
	if((*str) == '\0')
	{
		return str;
	}
	
	if((*str) >= 'A' && (*str) <= 'Z')
	{
		(*str) = (*str) + 'a' - 'A';
	}
	
	toLowerCase(str + 1);
	
	return str;
}
```
迭代
```
char * toLowerCase(char * str){
	
    char* ptr = str; 
	while((*ptr) != '\0')
	{
		if((*ptr) >= 'A' && (*ptr) <= 'Z')
		{
			(*ptr) = (*ptr) + 'a' - 'A';
		}

		ptr++;
	}
	return str;
}
```
