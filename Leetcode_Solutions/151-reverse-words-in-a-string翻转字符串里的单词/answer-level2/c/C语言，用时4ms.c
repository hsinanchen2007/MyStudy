## 思路
  先去除两端空格，再开辟一个字符数组的空间用于存放逆置的字符串，具体做法为从后遍历，每遇到一个空格便复制到新的字符数组中
## 代码
```
char * reverseWords(char * s){

    // 异常处理
    if (s == NULL)
        return "" ;
    // 去除字符串前面的空格
    while(*s == ' '){
        s++;
    }
    // 极端情况下除去空格可能为空，这时直接返回空，否则说明字符串非纯空格组成
    if(strlen(s) == 0)
        return "" ;
    char *end = s + strlen(s) - 1;
    // 去除字符串后面的空格，注意这里不需要判断是否为空的情况
    while(*end == ' ' && s <= end)
        end--;
    *(end + 1) = '\0';/*补上终止符*/

    // 新建一个字符数组用于存放逆序字符串
    char *new = (char *) malloc (sizeof(char) *(strlen(s) + 1));
    // currentwordLen表示每个空格被空格分隔的单词的长度（从后往前数）
    int currentwordLen = 0;
    // wordLen统计当前字符串的真实长度（去除了冗余的空格）
    int wordLen = 0;
    // ptr遍历指针
    char *ptr;
    // 从后往前遍历，依次统计每个单词的长度currentwordLen
    for (ptr = end; ptr >= s; ptr--){
        while( *ptr != ' ' && ptr > s){
            currentwordLen++;
            ptr--;
        }
        /*跳出while循环有两种情况需分别处理，一种是ptr指向空格，一种是遍历到字符串开头（这时再执行ptr--会报错）*/
        if(ptr == s){/*考虑到极端情况下可能遍历到字符首字母处，这时不存在遍历到空格再复制的操作，所以先判断这种极端情况，*/
            strncpy(new + wordLen,ptr, currentwordLen + 1);/*加一是考虑到给单词后添加一个空格占据了一个单位长度*/
            wordLen += currentwordLen;/*更新新字符串长度*/
            *(new + wordLen + 1) = '\0';
            return new;
        }else if (currentwordLen > 0){ /*一般的处理遇到空格时的复制*/
            strncpy(new + wordLen,ptr+1, currentwordLen);/*ptr+1对应的是空格后的那个单词的首字母的*/
            wordLen += currentwordLen;/*更新新字符串长度*/
            *(new + wordLen) = ' ';
            wordLen++;
            currentwordLen = 0;
        }

    }
    return new;
}
```
