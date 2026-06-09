### 解题思路

思路：统计杂志内字符出现的次数，再扫描dst一旦对应字符统计出现负值，就错了。

### 代码

```c
bool canConstruct(char * ransomNote, char * magazine){
	int len1 = strlen(ransomNote), len2=strlen(magazine);

	if(len1>len2) return false;
	int charMap[2000] = {0};

	// 统计每个字母出现的次数
	for(int j=0;j<len2;j++){
		charMap[magazine[j]]++;
	}

	for(int i=0;i<len1;i++){
		charMap[ransomNote[i]]--;
		if(charMap[ransomNote[i]]<0) return false;
	}
	return true;	
}
```