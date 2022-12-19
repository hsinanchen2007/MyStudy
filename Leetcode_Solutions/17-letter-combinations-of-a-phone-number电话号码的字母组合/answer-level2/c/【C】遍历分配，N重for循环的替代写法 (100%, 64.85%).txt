### 解题思路
![image.png](https://pic.leetcode-cn.com/d395fbfc3424a55182715d10e417523111b349e66c3d40c9dfecd8d00001e5c4-image.png)
C语言坑爹的二级指针，申请内存异常判断花了一大半时间，真正代码也就十几行
输入长度为n的字符串，易知需要返回(cnt[0] * cnt[1] * …… * cnt[n-1])组字符串，每组字符串长度为n

写法一：用n重for循环进行遍历
```
for (loop0 = 0; loop0 < cnt[0]; loop0++) {
    for (loop1 = 0; loop1 < cnt[1]; loop1++) {
        /******省略若干个loop******/
        for (loopn = 0; loopn < cnt[n]; loopn++) {

        }
    }
}
```
写法二：由于n未知，且没人会闲着无聊手写那么多循环。。。以上n重循环可以换一种写法，即每一层循环记满时，本层循环清零，上一层循环+1，这样就可以用一个标记数组和一重循环代替n重循环
```
int *flag = (int*)malloc(sizeof(int)*n);
memset(flag, 0, sizeof(int)*n);

while() {
    flag[0]++;
    for(i = 0; i < n; i++) {
        if (flag[i] == max) {
            flag[i] = 0;
            flag[i+1]++;
        }
    }
}

```

### 代码

```c
char table[8][4] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int cnt[8] = {3, 3, 3, 3, 3, 4, 3, 4};

char ** letterCombinations(char * digits, int* returnSize){
    int strLen = strlen(digits);
    if (strLen == 0) {
        *returnSize = 0;
        return 0;
    }

    int strNum = 1;
    for (int i = 0; i < strLen; i++) {
        strNum *= cnt[digits[i]-'2'];
    }
    //printf("digits = %s, strNum = %d, strLen = %d\n", digits, strNum, strLen);
    char **buffOut;
	buffOut = (char **)malloc(sizeof(char *) * strNum);
	for (int i = 0; i < strNum; i++) {
		buffOut[i] = (char *)malloc(sizeof(char) * (strLen + 1));
	}

    /* 遍历分配 */
    int x, y, i, tmp;
    int *flag = (int*)malloc(sizeof(int)*strLen);
    memset(flag, 0, sizeof(int)*strLen);
    for (x = 0; x < strNum; x++) {
        for (y = 0; y < strLen; y++) {
            tmp = digits[y]-'2';
            buffOut[x][y] = table[tmp][flag[y]];
        }
        buffOut[x][strLen] = '\0';
        flag[0]++;
        for(i = 0; i < strLen; i++) {
            if (flag[i] == cnt[digits[i]-'2']) {
                flag[i] = 0;
                if (i + 1 < strLen) {
                    flag[i+1]++;
                }
            }
        }
    }

	*returnSize = strNum;
    return buffOut;
}
```