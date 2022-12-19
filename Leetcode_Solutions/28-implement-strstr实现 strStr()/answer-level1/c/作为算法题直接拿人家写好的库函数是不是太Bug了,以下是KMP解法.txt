采用kmp方式
```
// 采用 kmp 方式匹配
int strStr(char * haystack, char * needle){

	// needle的长度
	int len_needle = 0;
	for(;needle[len_needle] != '\0';len_needle++){

	}

	// 如果 needle 是空串直接返回0
	if(len_needle == 0)
		return 0;

	// next数组
	int  *next = (int*)malloc(sizeof(int) * len_needle);
 	
 	// 填充next数组
    next[0] = -1;
	for(int j = 0,k =  -1;j < len_needle - 1;){
		if( k ==  -1  || needle[j] == needle[k]){
			next[++j] =  ++k;
		}else{
			k = next[k];
		}
	}

	//  kmp模式匹配
    int i = 0,j = 0;
    // 这里不能用 needle[j] != '\0' 判断，因为j可能会回溯到 -1，这样对数组进行操作可能
    // 会出现问题
	for(;haystack[i] != '\0' && j < len_needle;){
		if(j == -1 || haystack[i] == needle[j]){
			i++;
			j++;
		}else{
			j = next[j];
		}
	}

	if(j + 1 > len_needle){
		return i - j;
	}else{
		return -1;
	}


}
```
