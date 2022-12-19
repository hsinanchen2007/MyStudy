### 解题思路
对于s从后往前进行查找，找了非空格的话就进入把这个单词的起止位置找到，然后把单词赋值给返回字符串。然后继续。

### 代码

```c
char * reverseWords(char * s){
    int len = strlen(s);
    char* new_s = (char*)malloc(sizeof(char)*(len+1));
    int prev, after, curr;  // 源字符串的某个单词起点，终点，当前索引位置
    int index;  // 返回字符串的索引

    prev = len-1;
    after = prev;
    index = 0;
    while(prev >= 0){  // prev, after从后往前查找
        if(s[prev] == ' '){
            prev--;
        }else{
            // after 标记单词末尾位置，prev标记单词起始位置(prev+1)
            after = prev;
            while(prev>=0 && s[prev] != ' '){
                prev--;
            }
            // 将单词每个字母都赋值给new_s
            curr = prev+1;
            while(curr <= after){
                new_s[index++] = s[curr++];
            }
            new_s[index++] = ' ';
        }
    }
    if(index > 0 && new_s[index-1] == ' '){
        new_s[index-1] = 0;  // 新字符串末尾多了空格的情况
    }else{
        new_s[index] = 0;  // 处理源字符串空或全是空格的情况
    }

    return new_s;
}

```