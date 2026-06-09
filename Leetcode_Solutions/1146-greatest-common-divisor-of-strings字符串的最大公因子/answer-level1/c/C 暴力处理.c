### 解题思路
1.先找到最小的串，检查是否能和自己匹配和长串匹配。
2.如果不能匹配，进行不停的等分判断。

### 代码

```c
/*X最长为最短的那个字符串，如果最短的那个字符串， 如果最短的那个不行，将最短的再切一半进行匹配*/

bool IsMath(char * str1, char *x, int xLen){
    //printf("%s\n", str1);
    int str1Len = strlen(str1);
    if (str1Len < xLen){
        return false;
    } else if (xLen == str1Len && strcmp(str1, x) == 0){
        return true;
    } 
    if (strstr(str1, x) == NULL){
        return false;
    }
    //printf("next :%s", str1 + xLen);
    return IsMath(str1 + xLen, x, xLen);
}

char * gcdOfStrings(char * str1, char * str2){
    char *langStr = str1;
    char *shortStr = str2;
    if (strlen(str2) > strlen(str1)){
        langStr = str2;
        shortStr = str1;
    }
    int shortStrLen = strlen(shortStr);
    //printf("%s\n", shortStr);
    int i = 1;
    while (shortStrLen > i ){
        //printf("i:%d\n", i);
        if ((shortStrLen % i != 0)){
            i++;
            continue;
        }
        int xLen = shortStrLen - shortStrLen / i;
        //printf("len:%d--> %s\n", shortStrLen / i, shortStr + xLen);
        if (!IsMath(shortStr, shortStr + xLen, shortStrLen / i)){
            i++;
            continue;
        } else if (!IsMath(langStr, shortStr + xLen, shortStrLen / i)){
            i++;
            continue;
        } else {
            return shortStr + xLen;
        }
    }
    return "";
}
```