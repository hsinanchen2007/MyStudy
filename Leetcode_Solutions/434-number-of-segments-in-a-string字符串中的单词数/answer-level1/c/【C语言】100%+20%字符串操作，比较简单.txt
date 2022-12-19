### 解题思路
1.思路比较简单：使用start作为单词开始的标记，然后开始遍历数组，遇到空格即为单词结束。
2.corner condition：
（1）.当最后一个单词时，不是以空格结尾，而是字符串的末尾，因此需要在for循环结束之后判断start标记是否为1，如果是，说明字符串最后有以非空格结尾的单词。需要统计进去。
3.经验教训：无。
4.耗时：13mins，还比较满意：
（1）盯准单词的定义包括非空格字符------读题准；
（2）如上面的corner condition所述------典型corner condition在编码时就考虑得比较全面；
![image.png](https://pic.leetcode-cn.com/589170918551e17a9f25276b33fc3eb67805385a44ab19f9f18de161037514b4-image.png)

......

### 代码

```c
int countSegments(char * s){
    int i = 0;
    int start = 0;
    int count = 0;
    int len = strlen(s);
    
    for(i = 0 ; i < len; i++) {
        if(start == 0 && s[i] != ' ') {
            start = 1;        }
        else if(start == 1 && s[i] != ' ') {
            continue;
        }
        else if(start == 1 && s[i] == ' ') {
            count++;
            start = 0;            
        }
    }
    if(start == 1) {
        count++;
        start = 0;
    }
    return count;
}
```