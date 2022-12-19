# C
- 指针后移
- 遇到空格count归0，并保存本次count
- 如果最后count为0，返回最后保存的count

```
int lengthOfLastWord(char * s){
    int index = 0;
    int count = 0;
    int lastCount = 0;
    while(*(s + index) != '\0') {
        if(*(s + index) == ' ') {
            if(count != 0) {
                lastCount = count;
            }
            count = 0;
        } else {
            count ++;
        }
        index++;
    }
    return count == 0? lastCount: count;
}
```

# Java
- 把字符串利用空格分割成数组
- 取最后一个字符串的长度
```
class Solution {
    public int lengthOfLastWord(String s) {
        String array[] = s.split(" ");
        if(array.length < 1) return 0;
        return array[array.length - 1].length();
    }
}
```

