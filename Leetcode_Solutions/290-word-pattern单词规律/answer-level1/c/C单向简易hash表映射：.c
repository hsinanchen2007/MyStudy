
![截图.PNG](https://pic.leetcode-cn.com/09c9770e80eb0f5842bbd2c47defa884c8648d4c5fd12c33acddfdc9eb2afbb3-%E6%88%AA%E5%9B%BE.PNG)

核心思想建立pattern->str和str->pattern的双向映射保证都是一一对应的
由于C没有内置hash表，pattern->str的映射可以用字符串数组（下标为字母编号）简单代替
str->pattern映射不好实现，用遍历方法保证str和pattern的一一对应


```
//字符串比较函数，可以用内置strcpy代替
/*
bool comparaStr(char* a, char* b) {
    while (*a != '\0' && *b != '\0') {
        if (*a != *b) {
            return false;
        }
        a++;
        b++;
    }
    if (*a != '\0' || *b != '\0') {
        return false;
    } else {
        return true;
    }
}
*/

bool wordPattern(char * pattern, char * str){
    char* patternArray[26]; // 保存pattern映射的字符串
    for (int i = 0; i < 26; ++i) {
        patternArray[i] = (char *)malloc(sizeof(char) * 100); 
        sprintf(patternArray[i], "");
    }
    int index = 0; // 原始字符串下标
    while (*pattern != '\0') { 
        if (str[index] == ' ') {
            index++;
        }
        int j = 0; //当前单词下标
        char temp[100] = ""; //保存当前单词
        while (str[index] != ' ' && str[index] != '\0') {
            temp[j] = str[index];
            index++;
            j++;
        }
        temp[j] = '\0';
        if (j == 0) { //str先到尾部时判断
            return false;
        }
              
        if (strlen(patternArray[*pattern - 'a']) == 0) { 
            // 当前pattern对应字符串为空时，校验str->pattern的映射关系，如果已有pattern对应字符串与新增单词temp相同，证明多个str映射到一个pattern,返回false
            for (int j = 0; j < 26; ++j) {
                if (strlen(patternArray[j]) != 0) {
                    if (strcmp(patternArray[j], temp) == 0) {
                        return false;
                    }
                }
            }
            sprintf(patternArray[*pattern - 'a'], "%s", temp); // 否则可以将temp增加到pattern中
        } else { //当前pattern对应字符串非空，与当前单词对比校验pattern->str的映射关系
            if (strcmp(patternArray[*pattern - 'a'], temp) != 0) {
                return false;
            }
        } 
        pattern++;  
    }
    if (*pattern != '\0' || str[index] != '\0') {
        return false;
    } else {
        return true;
    }
}
```
