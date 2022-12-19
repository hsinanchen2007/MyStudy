// 字符c在子字符串中的位置，不存在则返回-1
int locInStr(char* s, int start, int end, char c)
{
    int i;
    if (end < start) {
        return -1;
    }

    for (i = start; i <= end; i++) {
        if (s[i] == c) {
            return i;
        }
    }
    return -1;
}

int lengthOfLongestSubstring(char* s)
{
    int len = strlen(s);
    if (len <= 1) {
        return len;
    }

    int i = 1;
    int start = 0;
    int end = 0;
    int max = 0;

    while (i < len) {
        end = i - 1;
        int loc = locInStr(s, start, end, s[i]);
        if (loc > -1) {
            if (max < end - start + 1) {
                max = end - start + 1;
            }
            start = loc + 1;
        }
        i = i + 1;
    }

    if (max < i - start) {
        max = i - start;
    }

    return max;
}
