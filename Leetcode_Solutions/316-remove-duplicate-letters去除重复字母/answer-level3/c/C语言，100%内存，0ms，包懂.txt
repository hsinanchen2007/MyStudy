详见注释，无需多言

```
char *removeDuplicateLetters(char *s)
{
    char *iter = s;
    char record[26] = {0};
    int sLen = strlen(s);
    int stackTop = -1;

    // 统计一下每个字母都有多少个
    while (*iter != '\0') {
        record[*iter - 'a']++;
        iter++;
    }

    // 遍历指针回到头，不重复申请内存
    iter = s;

    while (*iter != '\0') {
        // 看一下待插入的字符，在栈里面是否已经存在，存在则调过这个iter指向的字符
        // 不存在则入栈这个字符
        int isExist = 0;
        for (int i = 0; i <= stackTop; i++) {
            if (s[i] == *iter) {
                isExist = 1;
                break;
            }
        }

        if (isExist == 0) {
            s[++stackTop] = *iter;
        }

        // 入栈某个字符，这个字符的record记录要相应减少
        record[*iter - 'a']--;

        // 从栈顶开始往下栈底检查，栈顶元素和它下一个元素的大小关系
        // 如果下一个元素比栈顶大，并且下一个元素，在后续iter即将便利到的列表中，也就是record记录中，还有同样的字符，则用栈底下降1
        // 反之不管
        while (stackTop - 1 >= 0 && s[stackTop - 1] > s[stackTop] && record[s[stackTop - 1] - 'a'] > 0) {
            s[stackTop - 1] = s[stackTop];
            stackTop--;
        }

        iter++;
    }

    // 因为没有申请额外空间，在栈顶下一个位置增加一个结束符
    s[stackTop + 1] = '\0';

    return s;
}
```
