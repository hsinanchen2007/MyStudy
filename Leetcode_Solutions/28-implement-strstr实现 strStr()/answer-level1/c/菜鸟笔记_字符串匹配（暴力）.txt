### 解题思路
1. 在if语句里面的自增语句，至少在if不生效的时候是不会生效的

### 代码

```c
//date：2020.3.5 13：00

bool isMatch(char* haystack, char* needle, int index){
    int i = 0;
    while ((haystack[index] != '\0') && (needle[i] != '\0')){
        if (haystack[index] != needle[i]){//判断符号内的自增，在判断不生效的时候不会起作用
            break;
        }
        index++;
        i++;
    }
    if (needle[i] == '\0'){
        return true;
    }
    else{
        return false;
    }
    
}
int strStr(char * haystack, char * needle){
    int index = 0;//用于haystack遍历

    if (needle[0] == '\0'){//两个都空
        return 0;
    }

    while (haystack[index] != '\0'){
        if (haystack[index] == needle[0]){
            if (isMatch(haystack, needle, index)){
                return index;
            }
        }
        index++;
    }

    return -1;
}
```