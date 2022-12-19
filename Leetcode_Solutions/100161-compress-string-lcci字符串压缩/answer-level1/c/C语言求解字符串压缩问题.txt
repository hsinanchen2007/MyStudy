### 解题思路
首先利用malloc创建一个新的字符串，从原字符串的第一个字符串出发开始遍历，首先原字符串当前指向的字符赋值给新串，并开始统计该字符在原串中连续出现的数量，统计方法是：利用循环比较当前字符和它后一个字符是否相等，若相等则当前指针往后移动一个位置，数量加1，持续如此直至不再相等。若数量小于10，则直接将数量+'0'赋值给新串，否则利用sprintf函数将数量转化为字符串，并将其赋值给新串，最后比较新串与原串的大小，若新串长度更小返回新串，否则返回原串。

### 代码

```c
#include <stdlib.h>
char* compressString(char* S) {
	if (strlen(S) == 1)
		return S;
	int i, j, k, n;
	char* outcome = (char*)malloc(sizeof(char) * strlen(S) * 2);
	char str[25];
	k = 0;
	for (i = 0; S[i]; i++)
	{
		outcome[k++] = S[i];
		j = 1;
		while (S[i] && (S[i] == S[i + 1]))
		{
			i++;
			j++;
		}
        if(j<10)
            outcome[k++] = '0' + j;
        else
        {
            sprintf(str, " %d", j);
		    n = 1;
		    while (str[n])
		    {
			    outcome[k++] = str[n++];
		    }
        }
	}
	outcome[k++] = '\0';
	if (strlen(outcome) < strlen(S))
		return outcome;
	return S;
}
```