### 解题思路

字符串的组成是由128个ACSII组成，定义一个128位的数组，用字符的值作为数组的下标，当存在某一位大于1，则表征出现了2次，返回false；否则返回true。
### 代码

```c
bool isUnique(char* astr){
	char test[128] = {0};
	int len = strlen(astr);
	for (int i = 0; i < len; i++) {
		test[astr[i]]++;
		if(test[astr[i]] >1) {
			printf("false\r\n");
			return false;
		}
	}
	printf("true\r\n");
	return true; 	
	
}
```