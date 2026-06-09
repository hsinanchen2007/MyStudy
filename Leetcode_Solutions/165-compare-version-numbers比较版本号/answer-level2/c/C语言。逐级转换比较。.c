```
int getCurVer(char* version, int* pos){
    int start = *pos;
	
    while(version[*pos] != '\0' && version[*pos] != '.'){
	(*pos)++;
     }
	
    if(version[*pos] == '.'){
	version[*pos] = '\0';
	(*pos)++;
    }
	
    return atoi(version + start);
}

int compareVersion(char * version1, char * version2){
    int pos1, pos2, num1, num2;
	
    pos1 = pos2 = 0;
    while(version1[pos1] != '\0' || version2[pos2] != '\0'){
	num1 = getCurVer(version1, &pos1);
	num2 = getCurVer(version2, &pos2);
		
	if(num1 > num2){
	    return 1;
	}else if(num1 < num2){
	    return -1;
	}
    }
	
    return 0;
}
```
