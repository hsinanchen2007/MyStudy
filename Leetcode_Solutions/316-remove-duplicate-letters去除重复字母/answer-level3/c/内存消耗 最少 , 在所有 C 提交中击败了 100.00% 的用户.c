### 解题思路
此处撰写解题思路
1.统计输入字符串s中各个字母出现的个数。
2.遍历输入字符串s：
2.1 s中的当前字符如果已经在结果字符串中，直接跳过；
2.2 s中的当前字符如果比结果字串的最后一个字符大，直接加入结果字符串；
2.3 s中的当前字符如果比结果字串的最后一个字符小，就在结果字符串中循环向前找：对于结果字符串中比当前字符大的，并且出现次数大于1的，全部可以删除。最后将该字符加入结果字符串。

注意：给字符串分配空间时和初始化时，一定要+1个空间存'\0'。

### 代码

```c
void ComputeLetterNum(char* s, char* letter, int size) 
{
    int i;
    memset(letter, 0, 26);
    for (i = 0; i < size; i++) {
        letter[s[i] - 'a']++;
    }
}

char * removeDuplicateLetters(char * s){
    char letter[26];
    char* ret;
    int i, j;
    int pos = 0;
    int size = strlen(s);
    ret = (char*)malloc(sizeof(char) * (size + 1));
    if (ret == NULL) {
        return NULL;
    }
    memset(ret, 0, sizeof(char) * (size + 1));
    
    ComputeLetterNum(s, letter, size);

    ret[pos++] = s[0];
    for (i = 1; i < size; i++) {
        printf("in for\n");
        for (j = 0; j < pos; j++) {
            if (ret[j] == s[i]) {
                break;
            }
        }
        if (j < pos) {
            letter[s[i] - 'a']--;
            //printf("skip :%c\n", s[i]);
            continue;
        }
        if (s[i] > ret[pos - 1]) {

        } else {
            while (pos > 0 && letter[ret[pos - 1] - 'a'] > 1 && s[i] <= ret[pos - 1]) {
                letter[ret[pos - 1] - 'a']--;
                //printf("out :%c, %d\n", ret[pos - 1], letter[ret[pos - 1] - 'a']);
                pos--;
            }
        }
        ret[pos++] = s[i];
        //printf("in :%c, %d\n", ret[pos - 1], letter[ret[pos - 1] - 'a']);
    }
    return ret;
}


```