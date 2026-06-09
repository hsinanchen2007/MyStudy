思路：
滑动窗口，每次从右边加入一个字符后，判断新字符和窗口里的其他字符是否有重复，如果有重复，左边窗口移动到冲突字符的后一个位置。如果没有冲突，最大长度加1。
代码：
int func(char* s, char c, int num) 
{
    int i;

    for (i = 0; i < num - 1; i++) {
        if (s[i] == c) {
            return i + 1;
        }
    }

    return 0;
}

int lengthOfLongestSubstring(char * s)
{
    int head = 0;
    int end = 0;
    int max = 1;
    int con = 0;
    int num;

    if (s == NULL || s[0] == '\0') {
        return 0;
    }

    for (head = 0, end = 1; *(s + end) != '\0'; end++) {
        num = end - head + 1;
        con = func(&s[head], s[end], num);
        if (con == 0) {
            if (num > max) {
                max = num;
            }
            continue;
        } else {
            head = head + con;
        }
    }

    return max;
}