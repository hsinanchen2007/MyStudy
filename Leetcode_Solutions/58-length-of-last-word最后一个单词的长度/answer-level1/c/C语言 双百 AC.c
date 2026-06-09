### 解题思路
从后往前，先确定最后一个单词末尾，再确定最后一个单词首位，相减。
![image.png](https://pic.leetcode-cn.com/58754c97619a429737557346ef3a9e113649d3c85eb8fa2727951618dbed6724-image.png)

### 代码

```c
int lengthOfLastWord(char * s){
    int start = -1;
    int end = -1;
    int length = strlen(s);
    for(int i = length-1; i > -1; i--){
        if(end == -1 && s[i] != ' '){
            end = i;
        }
        if(end != -1 && s[i] == ' '){
            start = i;
            break;
        }
    }
    return end-start;
}
```