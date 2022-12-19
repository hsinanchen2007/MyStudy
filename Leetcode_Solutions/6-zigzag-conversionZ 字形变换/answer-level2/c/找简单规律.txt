```
char * convert(char * s, int numRows){
	int len = strlen(s);
	int k = numRows;
	int flag1=0;
    int count=0;
	int step1,step2;
    char *new1 = (char *)malloc(sizeof(char) * (len + 1));
	step1 = 2*numRows-2;
    if(numRows==1)
        return s;
	for(;numRows>=1;){
		if(numRows==k||numRows==1){
			for(int i=k-numRows;i<len;){
				new1[count]=s[i];
				i+=step1;
                count++;
			}
			numRows--;
		}
		else if(numRows!=k&&numRows!=1){
			step2 = 2*numRows-2;
			for(int i=k-numRows;i<len;){
				new1[count]=s[i];
                count++;
				if(flag1==0){
					i+=step2;
					flag1=1;
				}
				else if(flag1==1){
					i=i+step1-step2;
					flag1=0;
				}
			}

            numRows--;
            flag1=0;
		}
	}
    new1[len] = '\0';
	return new1;
}
```

