思路：倒序遍历源字符串，将依次找到的单词在返回结果字符串中正序摆放。
- 时间复杂度$O(N)$
- 空间复杂度$O(1)$
```c
char* reverseWords(char* s){
    int len = strlen(s); // 求字符串长度
    char* rw = NULL; // 返回结果
    int p1 = len - 1, p2; // 双索引标定一个单词的起始与结尾
    int count = 0; // 暂存返回字符串的长度
    while(p1 > -1 && p2 > -1){
        while(p1 > -1 && s[p1] == ' '){ // 从末尾开始遍历，寻找第一个单词的结尾
            p1--;
        }
        if(p1 == -1){ // 字符串中没有非空格以外的字符，直接退出
            break;
        }
        p2 = p1;
        while(p2 > -1 && s[p2] != ' '){ // 寻找当前单词的开头
            p2--;
        }

        if(rw == NULL){ // 将单词存储到rw中
            count += p1 - p2 + 1; // 多分配一个大小为sizeof(char)的空间放空格
            rw = (char*)malloc(count * sizeof(char));
            memcpy(rw, s + p2 + 1, (p1 - p2) * sizeof(char));
            rw[count - 1] = ' ';
        }
        else{
            int t = count;
            count += p1 - p2 + 1;
            rw = (char*)realloc(rw, count * sizeof(char));
            memcpy(rw + t, s + p2 + 1, (p1 - p2) * sizeof(char));
            rw[count - 1] = ' ';
        }
        
        p1 = p2; // p2此时指向当前单词头部前一个位置，将p1转移至p2，开始寻找下一个单词
    }

    if(count != 0){
        rw[count - 1] = '\0'; // 将最后一个空格变为'\0'
    }
    else{ // 源字符串s中不包含任何单词
        rw = (char*)malloc(sizeof(char));
        rw[0] = '\0';
    }
    return rw;
}
```
