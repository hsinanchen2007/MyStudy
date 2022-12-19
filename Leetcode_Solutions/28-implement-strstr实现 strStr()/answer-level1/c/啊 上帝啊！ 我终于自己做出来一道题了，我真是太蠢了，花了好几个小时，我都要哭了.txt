### 解题思路
此处撰写解题思路

### 代码

```c
int strStr(char * haystack, char * needle){
    int lengthstack = strlen(haystack);
	int lengthneedle = strlen(needle);
	int i = 0;
	int j = 0;
	int k = 0;
	int result = -1;

	if (lengthneedle == 0) {

		return 0;
	}

	if (lengthstack == 0){		//haystack为空肯定与needle没有一样的

		return -1;
	}

	if (lengthstack < lengthneedle){			//haystack的字符比needle少肯定没有一样的

		return -1;
	}

	for (; i < lengthneedle; i++) {

		for (; j < lengthstack; j++) {

			if (haystack[j] == needle[i]) {		//第一个字母匹配上了

				if (result == -1) {

					result = j;		//记录匹配上的第一个字母的下标
				}
				j++;		//因为匹配上了就break不需要再遍历剩下的,i++之后j又是从头遍历所以j++

				if ((j == lengthstack) && (i != lengthneedle - 1)) {

					return -1;		//要是j遍历到最后一位了，而i还不是最后一位，返回-1
				}

				break;
			}

			if (j == lengthstack - 1 && result == -1) {		//字符串中第一个字母都没匹配上就返回-1

				return -1;
			}

			if (result != -1) {		//第一个字母匹配上了，要是后面有一个不匹配，就继续遍历

				if (haystack[j] != needle[i]) {

					k++;			//给j赋值，让j从上一次匹配了字符之后的下一个位置开始继续遍历
					i = 0;
					j = k;
					i = -1;		//break之后要使i从头开始
					result = -1;		//重新开始遍历，所以就要重新获取匹配的下标
				}
				break;
			}
		}
	}

	return result;
}
```