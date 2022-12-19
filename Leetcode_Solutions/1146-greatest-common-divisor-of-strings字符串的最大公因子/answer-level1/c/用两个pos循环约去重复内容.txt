### 解题思路
1. 假設str1=TTT..TT, str2=TT..T，则我们总可以用短的str约去长的str
2. 用两个位置pos1,pos2记录当前约掉的位置
3. 当str1+pos1和str2+pos2相同字符串时，即为答案
4. 当str1+pos1和str2+pos2不同，但长度相等时，说明无解

### 代码

```c
char * gcdOfStrings(char * str1, char * str2){
    if (!str1 || !str2) return "";

    int pos1=0;
    int pos2=0;

    while (1) {
        int len1=strlen(str1+pos1);
        int len2=strlen(str2+pos2);

        if (!strcmp(str1+pos1, str2+pos2)) {
            return str1+pos1;
        }

        if (len1 == len2)  {
            return "";
        }

        if (len1 > len2) {
            pos1 += strlen(str2+pos2);
        } else {
            pos2 += strlen(str1+pos1);
        }
    }
    return "";    
}
```