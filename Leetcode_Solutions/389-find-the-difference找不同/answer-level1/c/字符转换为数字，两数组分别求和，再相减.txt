### 解题思路

![image.png](https://pic.leetcode-cn.com/f32d9afaeaef510db58fe936a8494e0643636c36d4cd0e4ca9e0aa12cc535419-image.png)

如题，两数组元素和之差就是新增的元素-'a'的值
### 代码

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char findTheDifference(char * s, char * t)
{
	int sumS = 0;
	int sumT = 0;
	char result;		

	while (*s) {
		sumS += (*s++) - 'a';
	}
	while (*t) {
		sumT += (*t++) - 'a';
	}
	
	result = sumT - sumS + 'a';
	return result;
}
```