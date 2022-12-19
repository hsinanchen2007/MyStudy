### 解题思路
没啥思路，有个坑需要注意一下：
"ab "

### 代码

```c
int lengthOfLastWord(char * s){
    int sLen = strlen(s);
    int index = 0;

    for (int i = sLen - 1; i >= 0; i--) {
        if(s[i] == ' ' && index == 0) {
            continue;            
        } else if (s[i] == ' ') {
            break;
        }
        index++;        
    }

    return index;
}
```