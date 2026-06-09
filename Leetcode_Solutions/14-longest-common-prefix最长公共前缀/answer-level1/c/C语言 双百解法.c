### 解题思路
1.首先因为要传入一个字符串数组和它的对应长度进而求得它的最长前缀，因此如果传入的字符串数组的size为0的话，那么就直接返回空字符串。
2.然后我们以第一个字符串strs[0]作为一个评判标准，将它的对应索引位置i与其他的字符串strs[j]中的对应索引位置做对比。对strsSize个字符串比对完成后如果都一样则添加到结果字符串res中。此时如果其他字符串中有空串就直接返回空字符串。如果对应索引位置的字符不一致或者已经到达对比字符串strs[j]的末尾的话，则将返回当前的结果res。
3.解法2中直接利用了字符串数组，没有重新申请内存空间。首先遍历一遍找到最短的字符串数组strs[minIndex]，然后以此为评判标准与其他字符串做对比。当出现不同时，将此时记录的位置的下一位置标记为'\0'，然后返回该地址strs[minIndex]即可。
### 代码
**解法1**
```c
char * longestCommonPrefix(char ** strs, int strsSize)
{
	if (strsSize == 0){
		return "";
	}
	int i = 0;
	int j;
	char *res = (char *)malloc(sizeof(char) * 1000);
	memset(res, 0, 1000);
	int flag = 0;
	while(strs[0][i] != '\0'){
		for(j = 1; j < strsSize; j++){
			if(strlen(strs[j])==0){
				return "";
			}
    		    
			if(strs[j][i]=='\0' || strs[0][i] != strs[j][i] ){				
				flag = 1;
			}
		}
		if(flag == 0){
			*(res+i) = strs[0][i];
		}else{
			break;
		}
		i++;
	} 
	
	return res;
}
```

**解法2**
```
char * longestCommonPrefix(char ** strs, int strsSize)
{
	if (strsSize == 0){
		return "";
	}
	
	int i = 0;
	int j;
	int flag = 0;
	int count = 0;
	int minLen = strlen(strs[0]);
	int minIndex = 0;
	for(j = 0; j < strsSize; j++){
		if(strlen(strs[j])==0){
			return "";
		}
		if (strlen(strs[j]) < minLen){
			minLen = strlen(strs[j]);
			minIndex = j;
		}
	}
	while(strs[minIndex][i] != '\0'){
		for(j = 0; j < strsSize; j++){ 
			if(strs[j][i]=='\0' || strs[minIndex][i] != strs[j][i] ){				
				flag = 1;
			}
		}
		if(flag == 0){
			count++;
		}else{
			break;
		}
		i++;
	} 
	if(count == 0){
		return "";
	}else{
		strs[minIndex][count] = '\0';
		return strs[minIndex];
	}
}
```
